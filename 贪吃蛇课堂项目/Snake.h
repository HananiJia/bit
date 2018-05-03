#ifndef __SNAKE_H__
#define __SNAKE_H__

// ��Ϸ�������꣨��Ӧ�� UI ��ʾ��ʱ������ַ�������
struct Position {
	int x;
	int y;
};

// ������
struct Node {
	struct Position position;
	struct Node *pNext;
};

// �߳���
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// �߽ṹ��
struct Snake {
	enum Direction direction;
	struct Node *pBody;
};

// ��Ϸ�ṹ��
struct Game {
	int width;	// ��Ϸ�����ȣ�������ǽ����Ӧ�� UI ���־����ַ�������
	int height;	// ��Ϸ����߶ȣ�������ǽ����Ӧ�� UI ���־����ַ�������
	int score;	// ��ǰ�÷�
	int scorePerFood;	// ÿ��ʳ��÷�

	struct Snake snake;	// ��
	struct Position foodPosition;	// ��ǰʳ������
};

#endif