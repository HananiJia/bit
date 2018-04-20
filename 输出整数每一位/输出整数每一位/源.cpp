#define _CRT_SECURE_NO_WARNINGS 1

 #include<stdio.h>
#include<math.h>
#include<stdlib.h>
 int main()
 {
     int num = 0;
     int i = 0;
	     int count = 0;
	     int num1 = 0;
		 double k = 0;
	     int a[100] = { 0 };
	     printf("please enter a number \n");
	     scanf("%d", &num);
	     num1 = num;
	     while (num>9)
		     {
		         num = num / 10;
		         count++;
		     }
		 k = count;
	     for (i = 0; i <= count; i++)
	     {
			 
		        a[i] = num1 / (pow(10.0, k));
				num1 = num1 - (a[i] * pow(10.0, k));
				k = k - 1;
		        printf("%d λ is %d \n", i + 1, a[i]);
		    }
		 system("pause");

	 }
