#define _CRT_SECURE_NO_WARNINGS 1


#include"OS.h"

_PCB* BuyNode(_PCB* pcb)
{
	char i = 0;
	int j = 0;
	int k = 0;
	_PCB* newNode = (_PCB*)malloc(sizeof(_PCB));
	if (NULL == newNode)
		return NULL;
	else
	{
		scanf("%c %d %d", &newNode->Name, &newNode->ArriveTime, &newNode->ServerTime);
		return newNode;
	}
}

void PushFront(_PCB** pcb)
{
	assert(pcb);
	if (*pcb == NULL)
	{
		(*pcb) = BuyNode((*pcb));
		return;
	}
	else
	{
		BuyNode(*pcb)->next = (*pcb);
		(*pcb) = BuyNode(*pcb);
	}
}

void InitPcb(_PCB** pcb)
{
	assert(pcb);
	if (NULL == (*pcb))
		return;
	(*pcb)->ArriveTime = 0;
	(*pcb)->FinishTime = 0;
	(*pcb)->Front = 0;
	(*pcb)->Name = '\0';
	(*pcb)->next = NULL;
	(*pcb)->ServerTime = 0;
	(*pcb)->StartTime = 0;
	(*pcb)->Time = 0;
	(*pcb)->ValueWholeTime = 0;
	(*pcb)->WholeTime = 0;
}

void Screen()
{
	printf("**************************\n");
	printf("1. 先来先服务\n");
	printf("2. 静态优先级服务\n");
	printf("3. 时间片轮转服务\n");
	printf("**************************\n");
}

void Input(_PCB** pcb)
{
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		PushFront(pcb);
	}
}

void Print(_PCB** pcb)
{
	assert(pcb);
	if (NULL == (*pcb))
		return;
	_PCB* cur = NULL;
	cur = (*pcb);
	printf("进程名\t到达时间\t服务时间\t开始执行时间\t完成时间\t周转时间\t带权周转时间\n");
	while (cur)
	{
		printf("%c\t%d\t%d\t%d\t%d\t%d\t%d\n", cur->Name, cur->ArriveTime, cur->ServerTime, cur->StartTime, cur->FinishTime, cur->WholeTime, cur->ValueWholeTime);
		cur = cur->next;
	}
}

void OrderServer(_PCB** pcb)
{
	assert(pcb);
	int i = 0;//记录当前是第几个进程
	if (NULL == (*pcb))
		return;
	_PCB* cur = NULL;
	_PCB* pre = NULL;//用来记录前一个结点，计算开始执行时间需要用到前一个结点的信息
	cur = pre = (*pcb);
	while (cur)
	{
		if (0 == i || 1 == i)//说明是第一个/第二个进程
		{
			if (0 == i)
			{
				cur->StartTime = cur->ArriveTime;
				i++;
			}
			else//是第二个进程，因为第二个进程的pre是头结点，所以不需要移动，单独出来
			{
				cur->StartTime = pre->FinishTime;
				i++;
			}
			cur->FinishTime = cur->ServerTime + cur->StartTime;
			cur->WholeTime = cur->FinishTime - cur->ArriveTime;
			cur->ValueWholeTime = cur->WholeTime / cur->ServerTime;
			cur = cur->next;
			i++;
		}
		else
		{
			pre = pre->next;
			cur->StartTime = pre->FinishTime;
			cur->FinishTime = cur->ServerTime + cur->StartTime;
			cur->WholeTime = cur->FinishTime - cur->ArriveTime;
			cur->ValueWholeTime = cur->WholeTime / cur->ServerTime;
			cur = cur->next;
			i++;
		}
	}
}

void Server(int n, _PCB** pcb)
{
	switch (n)
	{
	case 1:
		OrderServer(pcb);
		Print(pcb);
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		printf("error");
		break;
	}
}