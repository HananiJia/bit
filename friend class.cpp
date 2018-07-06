#include<iostream>
using namespace std;
class A{
    public:
    friend class B;
     A()
     {
         n=0;
         cout<<"class a construct"<<endl; 
     }
    private:
    int n;

};

class B{
    public:
    B()
    {
        A a;
        m=1;
        cout<<"class b construct"<<endl;
        show(a);
    }
   void  show(A &a)
   {
       cout<<"a is "<<a.n<<endl;
   }
   private:
    int m;
};

int main()
{
    B b;
    return 0;
}

