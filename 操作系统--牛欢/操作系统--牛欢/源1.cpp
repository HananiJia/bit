#define _CRT_SECURE_NO_WARNINGS 1

#include"OS.h"

int main()
{
	_PCB* pcb;
	int num = 0;
	InitPcb(&pcb);
	Screen();
	printf("������\t����ʱ��\t����ʱ��\n");
	Input(&pcb);
	int i = 0;
	printf("��������Ҫѡ��ķ���");
	printf("%d\n", scanf("%d", &num));
	Server(num, &pcb);
	return 0;
}