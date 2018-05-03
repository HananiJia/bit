#ifndef __UI_H__
#define __UI_H__


struct UI {
	// 边缘宽度（字符宽度）
	int marginTop;
	int marginLeft;

	// 游戏区域的字符个数
	int gameWidth;
	int gameHeight;

	// 整个窗口大小字符宽度/高度
	int windowWidth;
	int windowHeight;

	char *snakeBlock;	// 蛇的显示块
	char *wallBlock;	// 墙的显示块
	char *foodBlock;	// 食物的显示块
	int blockWidth;		// 每个块的宽度，注意，上面几个块的宽度要相等，否则就对不齐了
};

// UI 初始化
struct UI * UIInitialize(int width, int height);

// 显示游戏向导
void UIDisplayWizard(const struct UI *pUI);

// 显示游戏整体，包括墙、右边的信息，不包括蛇和食物的显示
void UIDisplayGameWindow(const struct UI *pUI, int score, int scorePerFood);

// 在x，y处显示食物，x，y都是字符个数
void UIDisplayFoodAtXY(const struct UI *pUI, int x, int y);

// 在x，y处显示蛇的一个结点，x，y都是字符个数
void UIDisplaySnakeBlockAtXY(const struct UI *pUI, int x, int y);

// 清空x，y处的显示块，x，y都是字符个数
void UICleanBlockAtXY(const struct UI *pUI, int x, int y);

// 显示分数信息
void UIDisplayScore(const struct UI *pUI, int score, int scorePerFood);

// 在游戏区域居中显示游戏退出消息
void UIShowMessage(const struct UI *pUI, const char *message);

// 销毁 UI 资源
void UIDeinitialize(struct UI *pUI);

#endif