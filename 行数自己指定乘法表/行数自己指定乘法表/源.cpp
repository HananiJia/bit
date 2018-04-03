#define _CRT_SECURE_NO_WARNINGS 1


  #include<stdio.h>
  int main()
   {
	int i = 0;
	     int n = 0;
	     int m = 0;
	     printf("please enter a number");
	     scanf("%d", &i);
	    for (m = 1; m <= i; m++)
		     {
		         for (n = 1; n <= m; n++)
			         {
			            printf("%2d*%2d=%2d", m, n, m*n);
			      }
		        printf("\n");
		     }
	
		 }


