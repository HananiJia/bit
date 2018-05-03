#ifndef __GAME_H__
#define __GAME_H__

#include "Snake.h"

// 创建并初始化游戏
struct Game * CreateGame();
// 开始游戏
void StartGame(struct Game *pGame);
// 销毁游戏资源
void DestroyGame(struct Game *pGame);

#endif