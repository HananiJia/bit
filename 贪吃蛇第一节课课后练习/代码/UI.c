#define _CRT_SECURE_NO_WARNINGS

#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// 移动光标到x，y处，注意，这里是相对整个屏幕的，而不是游戏区域的
static void _SetPos(int x, int y);

// 显示墙
static void _DisplayWall(const struct UI *pUI);

// 显示右侧信息
static void _DisplayDesc(const struct UI *pUI);

// 将游戏盘的x，y坐标转换为相对整个屏幕的x，y，也就是把字符个数转成最后的字符宽度
static void _CoordinatePosAtXY(const struct UI *pUI, int x, int y);

// 重置光标到屏幕下方，主要是为了显示的美观
static void _ResetCursorPosition(const struct UI *pUI);


struct UI * UIInitialize(int width, int height)
{
	const int left = 2;
	const int top = 2;
	const int blockWidth = 2;
	const int descWidth = 50;

	struct UI *pUI = (struct UI *)malloc(sizeof(struct UI));
	pUI->gameWidth = width;
	pUI->gameHeight = height;
	pUI->marginLeft = left;
	pUI->marginTop = top;
	pUI->windowWidth = left + (width + 2) * blockWidth + descWidth;
	pUI->windowHeight = top + height + 2 + 3;
	pUI->foodBlock = "█";
	pUI->snakeBlock = "█";
	pUI->wallBlock = "█";
	pUI->blockWidth = strlen(pUI->wallBlock);

	char modeCommand[1024];
	sprintf(modeCommand, "mode con cols=%d lines=%d", pUI->windowWidth, pUI->windowHeight);
	system(modeCommand);

	return pUI;
} 

void UIDisplayWizard(const struct UI *pUI)
{
	int i;
	const char *messages[3] = {
		"欢迎来到贪吃蛇小游戏",
		"用↑.↓.←.→分别控制蛇的移动， F1为加速，F2为减速。",
		"加速将能得到更高的分数。"
	};

	i = 0;
	_SetPos(pUI->windowWidth / 2 - strlen(messages[i]) / 2, pUI->windowHeight / 2);
	printf("%s\n", messages[i]);
	_SetPos(pUI->windowWidth / 2 - strlen(messages[i]) / 2, pUI->windowHeight / 2 + 2);
	system("pause");
	system("cls");

	i = 1;
	_SetPos(pUI->windowWidth / 2 - strlen(messages[i]) / 2, pUI->windowHeight / 2);
	printf("%s\n", messages[i]);

	i = 2;
	_SetPos(pUI->windowWidth / 2 - strlen(messages[i]) / 2, pUI->windowHeight / 2 + 2);
	printf("%s\n", messages[i]);
	_SetPos(pUI->windowWidth / 2 - strlen(messages[i]) / 2, pUI->windowHeight / 2 + 4);
	system("pause");
	system("cls");
}

void UIDisplayGameWindow(const struct UI *pUI, int score, int scorePerFood)
{
	_DisplayWall(pUI);
	UIDisplayScore(pUI, score, scorePerFood);
	_DisplayDesc(pUI);

	_ResetCursorPosition(pUI);
}

void UIDisplayFoodAtXY(const struct UI *pUI, int x, int y)
{
	_CoordinatePosAtXY(pUI, x, y);
	printf(pUI->foodBlock);

	_ResetCursorPosition(pUI);
}

void UIDisplaySnakeBlockAtXY(const struct UI *pUI, int x, int y)
{
	_CoordinatePosAtXY(pUI, x, y);
	printf(pUI->snakeBlock);

	_ResetCursorPosition(pUI);
}

void UICleanBlockAtXY(const struct UI *pUI, int x, int y)
{
	_CoordinatePosAtXY(pUI, x, y);
	int i;

	for (i = 0; i < pUI->blockWidth; i++) {
		printf(" ");
	}

	_ResetCursorPosition(pUI);
}

void UIDisplayScore(const struct UI *pUI, int score, int scorePerFood)
{
	int blockWidth = strlen(pUI->wallBlock);
	int left = pUI->marginLeft + (pUI->gameWidth + 2) * blockWidth + 2;
	_SetPos(left, pUI->marginTop + 8);
	printf("得分: %3d，每个食物得分: %3d", score, scorePerFood);

	_ResetCursorPosition(pUI);
}

void UIShowMessage(const struct UI *pUI, const char *message)
{
	// 左填充宽度 + (1(左边界个数）+游戏区域的个数/2) * 每个字符的宽度
	// - 字符串的宽度 / 2
	_SetPos(
		pUI->marginLeft + (
		(1 + pUI->gameWidth / 2) * pUI->blockWidth)
		- strlen(message) / 2,
		pUI->marginTop + 1 + pUI->gameHeight / 2);
	printf("%s\n", message);

	_ResetCursorPosition(pUI);
}

void UIDeinitialize(struct UI *pUI)
{
	free(pUI);
}

static void _DisplayWall(const struct UI *pUI)
{
	// 留给大家实现
}

static void _DisplayDesc(const struct UI *pUI)
{
	int left = pUI->marginLeft + (pUI->gameWidth + 2) * pUI->blockWidth + 2;
	const char *messages[] = {
		"不能穿墙，不能咬到自己。",
		"用 ↑ ↓ ← → 分别控制蛇的移动。",
		"F1 为加速，F2 为减速。",
		"ESC 退出游戏。 SPACE 暂停游戏。",
		"版权 @比特科技"
	};
	int i;

	for (i = 0; i < sizeof(messages) / sizeof(char *); i++) {
		_SetPos(left, pUI->marginTop + 10 + i);
		printf("%s\n", messages[i]);
	}
}

static void _SetPos(int x, int y)
{
	// 留给大家实现
	COORD position = { x, y };
}

static void _CoordinatePosAtXY(const struct UI *pUI, int x, int y)
{
	_SetPos(pUI->marginLeft + (1 + x) * pUI->blockWidth,
		pUI->marginTop + 1 + y);
}

static void _ResetCursorPosition(const struct UI *pUI)
{
	_SetPos(0, pUI->windowHeight - 1);
}