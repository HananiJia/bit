#ifndef __GAME_H__
#define __GAME_H__

#include "Snake.h"

// ��������ʼ����Ϸ
struct Game * CreateGame();
// ��ʼ��Ϸ
void StartGame(struct Game *pGame);
// ������Ϸ��Դ
void DestroyGame(struct Game *pGame);

#endif