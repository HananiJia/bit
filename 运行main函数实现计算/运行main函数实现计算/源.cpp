#include <stdio.h>
#include <string.h>  
#include <stdlib.h>  


int main(int argc, char* argv[])
{

	int ret = 0;
	
	if (argv[1][0] == '-')
	{
		switch (argv[1][1])//"-a"  
		{
		case 'a':
			ret = (atoi(argv[2])) + (atoi(argv[3]));
			break;
		case 's':
			ret = (atoi(argv[2])) - (atoi(argv[3]));
			break;
		case 'm':
			ret = (atoi(argv[2])) * (atoi(argv[3]));
			break;
		case 'd':
			ret = (atoi(argv[2])) /(atoi(argv[3]));
			break;
		default:
			printf("�ڶ�����������\n");
			break;
		}
	}
	else
		printf("�������\n");
	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}