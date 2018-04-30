#ifndef __SNAKE_H__
#define __SNAKE_H__

// 游戏区域坐标（对应到 UI 显示的时候就是字符个数）
struct Position {
	int x;
	int y;
};

// 链表结点
struct Node {
	struct Position position;
	struct Node *pNext;
};

// 蛇朝向
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// 蛇结构体
struct Snake {
	enum Direction direction;
	struct Node *pBody;
};

// 游戏结构体
struct Game {
	int width;	// 游戏区域宽度（不包括墙，对应到 UI 部分就是字符个数）
	int height;	// 游戏区域高度（不包括墙，对应到 UI 部分就是字符个数）
	int score;	// 当前得分
	int scorePerFood;	// 每个食物得分

	struct Snake snake;	// 蛇
	struct Position foodPosition;	// 当前食物坐标
};

#endif