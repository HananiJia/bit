#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

void FoundWords(FILE *pIn)
{
	char words[20];
	char ch[20];
	char IsEnd;
	int count = 0, len;
	int i;
	printf("请输入你要查找的词：");
	scanf("%s", words);
	len = strlen(words);
	while (1)
	{
	flag:
		IsEnd = fgetc(pIn);
		if (IsEnd == EOF)
		{
			break;
		}
		ungetc(IsEnd, pIn);
		for (i = 0; i < len; i++)
		{
			ch[i] = fgetc(pIn);
			if (ch[i] != words[i])
			{
				for (; i > 0; i--)
				{
					ungetc(ch[i], pIn);
				}
				goto flag;
			}
			else
			{
				if (i == len - 1)
				{
					count++;
				}
			}
		}
	}
	printf("%s出现的个数为：", words);
	printf("%d\n", count);
	system("pause");
}


int main()
{
	const char *INPUT = "word.txt";
	FILE *pIn = fopen(INPUT, "r");
	assert(pIn != NULL);
	FoundWords(pIn);
	fclose(pIn);
	return 0;
}