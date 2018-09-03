#include<stdio.h>
#include<stdlib.h>

class Solution {
    public:
            int rectCover(int number) {
    if(number<=0)
        return 0;
    if(number==1)
        return 1;
    if(number==2)
        return 2;
    int n1=1;
    int n2=2;
    int n3=0;
    int i=3;
    for(;i<=n;i++)
    {
       n3=n2+n1;
       n1=n2;
       n2=n3;
    }
   return n3;
                    }
};
