#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
int my_strcmp(const char *msg, const char *det)
{
	assert(msg || det);
	while ((*msg != NULL) && (*det != NULL))
	{
		if (*msg > *det)
			return 1;
		if (*msg < *det)
			return -1;
		else
		{
			*msg++;
			*det++;
		}
	}
	if ((*msg == '\0') && (*det != '\0'))
	{
		return -1;
	}
	if ((*msg != '\0') && (*det == '\0'))
	{
		return 1;
	}
	return 0;
}
int main()
{
	char *a = "asdxsf";
	char *b = "asdxsfq";
	int m = 0;
	m = my_strcmp(a, b);
	printf("%d", m);
	system("pause");

}
