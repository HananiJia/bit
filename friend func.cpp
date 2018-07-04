#include<iostream>
using namespace std;
class test{
    public:
    test(int n=2)
    { 
        date=n;
    }

    friend  void show(int n,test &a)
     {
         a.date=n;
         cout<<" a.date" <<a.date<<endl;
     }

    private:
       int date;
};

int main()
{
    test a(3);
    show(2,a);
}
