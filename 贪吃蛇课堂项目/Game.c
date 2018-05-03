#include "Game.h"
#include "UI.h"
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

// @ 刘大智同学指出 BUG


static void _Pause();

static void _InitializeSnake(struct Snake *pSnake)
{
}

static int _IsOverlapSnake(const struct Snake *pSnake, int x, int y)
{
}

static void _GenerateNewFood(struct Game *pGame)
{
}


struct Game * CreateGame()
{
	struct Game *pGame = (struct Game *)malloc(sizeof(struct Game));
	// TODO: 异常处理
	pGame->width = 28;
	pGame->height = 27;
	pGame->score = 0;
	pGame->scorePerFood = 10;

	// 关于蛇的初始化和放置食物部分，感兴趣的同学可以做扩展练习
	_InitializeSnake(&pGame->snake);
	_GenerateNewFood(pGame);

	return pGame;
}

static void _DisplaySnake(const struct UI *pUI, const struct Snake *pSnake)
{
}

static struct Position _GetNextPosition(const struct Snake *pSnake)
{
	struct Position nextPosition = { 0 };
	
	return nextPosition;
}

static int _IsWillEatFood(struct Position foodPosition, struct Position nextPosition)
{
}

static void _GrowAndMoveAndDisplay(const struct UI *pUI, 
			struct Snake *pSnake, 
			struct Position nextPosition)
{
}

static void _UpdateScoreAndDisplay(const struct UI *pUI, struct Game *pGame)
{
}


static void _AddHeadAndDisplay(const struct UI *pUI, struct Snake *pSnake,
struct Position nextPosition)
{
}

static void _RemoveTailAndDisplay(const struct UI *pUI, struct Snake *pSnake)
{
}

static void _MoveAndDisplay(const struct UI *pUI, struct Snake *pSnake, 
			struct Position nextPosition)
{
}

static int _IsKilledByWall(const struct Snake *pSnake, int width, int height)
{
}

static int _IsKilledBySelf(const struct Snake *pSnake)
{
}

static void _HandleDirection(struct Snake *pSnake)
{
	if (GetAsyncKeyState(VK_UP)) {
		if (pSnake->direction != DOWN) {
			pSnake->direction = UP;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		if (pSnake->direction != UP) {
			pSnake->direction = DOWN;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT)) {
		if (pSnake->direction != RIGHT) {
			pSnake->direction = LEFT;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		if (pSnake->direction != LEFT) {
			pSnake->direction = RIGHT;
		}
	}
}

void StartGame(struct Game *pGame)
{
	struct UI *pUI = UIInitialize(pGame->width, pGame->height);

	UIDisplayWizard(pUI);
	UIDisplayGameWindow(pUI, pGame->score, pGame->scorePerFood);
	UIDisplayFoodAtXY(pUI, pGame->foodPosition.x, pGame->foodPosition.y);
	_DisplaySnake(pUI, &pGame->snake);

	while (1) {
		// 方向
		_HandleDirection(&pGame->snake);

		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}

		if (GetAsyncKeyState(VK_SPACE)) {
			_Pause();
		}

		struct Position nextPosition = _GetNextPosition(&pGame->snake);
		if (_IsWillEatFood(pGame->foodPosition, nextPosition)) {
			_GrowAndMoveAndDisplay(pUI, &pGame->snake, nextPosition);
			_UpdateScoreAndDisplay(pUI, pGame);
			_GenerateNewFood(pGame);
			UIDisplayFoodAtXY(pUI, pGame->foodPosition.x, pGame->foodPosition.y);
		} else {
			_MoveAndDisplay(pUI, &pGame->snake, nextPosition);
		}

		if (_IsKilledByWall(&pGame->snake, pGame->width, pGame->height)) {
			break;
		}
		else if (_IsKilledBySelf(&pGame->snake)) {
			break;
		}

		Sleep(300);
	}

	UIShowMessage(pUI, "游戏结束");

	UIDeinitialize(pUI);
}

static void _DestroySnake(struct Snake *pSnake)
{
}

void DestroyGame(struct Game *pGame)
{
	struct Node *pNode, *pNext;
	
	_DestroySnake(&pGame->snake);

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