#define _CRT_SECURE_NO_WARNINGS 1
   #include<stdio.h>

  int main()
   {
	     int m = 0;
     int n = 0;
	     int count = 0;
	    printf("please enter m\n");
	     scanf("%d", &m);
     printf("please enter n\n");
	     scanf("%d", &n);
	     m = m^n;
	    while (m>0)
		     {
		         if ((m & 1) == 1)
		             count++;
	        m = m >> 1;
	    }
     printf("二进制中有%d个不同", count);
	 }


