#include "Game.h"
#include "UI.h"
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>


static void _Pause();


struct Game * CreateGame()
{
	struct Game *pGame = (struct Game *)malloc(sizeof(struct Game));
	// TODO: �쳣����
	pGame->width = 28;
	pGame->height = 27;
	pGame->score = 0;
	pGame->scorePerFood = 10;

	// �����ߵĳ�ʼ���ͷ���ʳ�ﲿ�֣�����Ȥ��ͬѧ��������չ��ϰ

	return pGame;
}

void StartGame(struct Game *pGame)
{
	// ������̰���߿��Ƶ���Ҫ���֣�����ұ����˻�û�����İ��������֣�Ŀǰ��֧�� ESC �˳�ѭ��
	// �����߼���ҿ��Գ���ȥ�Լ�ʵ����
	// MSDN ��ַ
	//	https://msdn.microsoft.com/en-us/library/windows/desktop/ms646293(v=vs.85).aspx
	//	https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx

	struct UI *pUI = UIInitialize(pGame->width, pGame->height);

	UIDisplayWizard(pUI);
	UIDisplayGameWindow(pUI, pGame->score, pGame->scorePerFood);

	while (1) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}

		Sleep(2000);
	}

	UIShowMessage(pUI, "��Ϸ����");

	UIDeinitialize(pUI);
}

void DestroyGame(struct Game *pGame)
{
	free(pGame);
}

static void _Pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}
}