#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "UI.h"

int main(int argc, const char *argv[])
{
	// 设置根据当前时间戳设置随机种子
	srand((unsigned int)time(NULL));

	struct Game *pGame = CreateGame();

	StartGame(pGame);

	DestroyGame(pGame);

	system("pause");

	return 0;
}