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
	printf("1. �����ȷ���\n");
	printf("2. ��̬���ȼ�����\n");
	printf("3. ʱ��Ƭ��ת����\n");
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
	printf("������\t����ʱ��\t����ʱ��\t��ʼִ��ʱ��\t���ʱ��\t��תʱ��\t��Ȩ��תʱ��\n");
	while (cur)
	{
		printf("%c\t%d\t%d\t%d\t%d\t%d\t%d\n", cur->Name, cur->ArriveTime, cur->ServerTime, cur->StartTime, cur->FinishTime, cur->WholeTime, cur->ValueWholeTime);
		cur = cur->next;
	}
}

void OrderServer(_PCB** pcb)
{
	assert(pcb);
	int i = 0;//��¼��ǰ�ǵڼ�������
	if (NULL == (*pcb))
		return;
	_PCB* cur = NULL;
	_PCB* pre = NULL;//������¼ǰһ����㣬���㿪ʼִ��ʱ����Ҫ�õ�ǰһ��������Ϣ
	cur = pre = (*pcb);
	while (cur)
	{
		if (0 == i || 1 == i)//˵���ǵ�һ��/�ڶ�������
		{
			if (0 == i)
			{
				cur->StartTime = cur->ArriveTime;
				i++;
			}
			else//�ǵڶ������̣���Ϊ�ڶ������̵�pre��ͷ��㣬���Բ���Ҫ�ƶ�����������
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