#define _CRT_SECURE_NO_WARNINGS 1

#include"OS.h"

int main()
{
	_PCB* pcb;
	int num = 0;
	InitPcb(&pcb);
	Screen();
	printf("进程名\t到达时间\t服务时间\n");
	Input(&pcb);
	int i = 0;
	printf("请输入你要选择的服务：");
	printf("%d\n", scanf("%d", &num));
	Server(num, &pcb);
	return 0;
}