#ifndef __UI_H__
#define __UI_H__


struct UI {
	// ��Ե��ȣ��ַ���ȣ�
	int marginTop;
	int marginLeft;

	// ��Ϸ������ַ�����
	int gameWidth;
	int gameHeight;

	// �������ڴ�С�ַ����/�߶�
	int windowWidth;
	int windowHeight;

	char *snakeBlock;	// �ߵ���ʾ��
	char *wallBlock;	// ǽ����ʾ��
	char *foodBlock;	// ʳ�����ʾ��
	int blockWidth;		// ÿ����Ŀ�ȣ�ע�⣬���漸����Ŀ��Ҫ��ȣ�����ͶԲ�����
};

// UI ��ʼ��
struct UI * UIInitialize(int width, int height);

// ��ʾ��Ϸ��
void UIDisplayWizard(const struct UI *pUI);

// ��ʾ��Ϸ���壬����ǽ���ұߵ���Ϣ���������ߺ�ʳ�����ʾ
void UIDisplayGameWindow(const struct UI *pUI, int score, int scorePerFood);

// ��x��y����ʾʳ�x��y�����ַ�����
void UIDisplayFoodAtXY(const struct UI *pUI, int x, int y);

// ��x��y����ʾ�ߵ�һ����㣬x��y�����ַ�����
void UIDisplaySnakeBlockAtXY(const struct UI *pUI, int x, int y);

// ���x��y������ʾ�飬x��y�����ַ�����
void UICleanBlockAtXY(const struct UI *pUI, int x, int y);

// ��ʾ������Ϣ
void UIDisplayScore(const struct UI *pUI, int score, int scorePerFood);

// ����Ϸ���������ʾ��Ϸ�˳���Ϣ
void UIShowMessage(const struct UI *pUI, const char *message);

// ���� UI ��Դ
void UIDeinitialize(struct UI *pUI);

#endif