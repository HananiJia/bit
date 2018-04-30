#include "Game.h"
#include "UI.h"
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>


static void _Pause();


struct Game * CreateGame()
{
	struct Game *pGame = (struct Game *)malloc(sizeof(struct Game));
	// TODO: 异常处理
	pGame->width = 28;
	pGame->height = 27;
	pGame->score = 0;
	pGame->scorePerFood = 10;

	// 关于蛇的初始化和放置食物部分，感兴趣的同学可以做扩展练习

	return pGame;
}

void StartGame(struct Game *pGame)
{
	// 这里是贪吃蛇控制的主要部分，给大家保留了还没讲到的按键处理部分，目前仅支持 ESC 退出循环
	// 其余逻辑大家可以尝试去自己实现下
	// MSDN 地址
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

	UIShowMessage(pUI, "游戏结束");

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