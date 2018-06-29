#include<iostream>
using namespace std;
class date
{
    public:
   
    date(int year=1990,int month=1,int day=1)
    :_year(year)
    ,_month(month)
    ,_day(day)
    {
        if(isinvalid(year,month,day))
            cout<<"date right"<<endl;
        else
            cout<<"date error"<<endl;
    }
    date(const date &d)
    {
        _year=d._year;
        _month=d._month;
        _day=d._day;
    }
    void print()
    {
        cout<<_year<<"-";
        cout<<_month<<"-";
        cout<<_day<<endl;
    }


    bool isLeapyear(int year)
    {
        if((year%4==0)&&(year%100!=0))
        {
            return true;
        }
        else
        {
            if(year%400==0)
                return true;
            else
                return false;
        }
     }
    int Getmonthday(int year,int month)
    {
        int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapyear(year)&&month==2)
            return a[month-1]+1;
        else
            return a[month-1];
    }
      bool isinvalid(int year,int month,int day)
      {
          if(year>=1900)
          {
              if(month>0&&month<=12)
              {
                  if(day>0&&(day<=Getmonthday(year,month)))
                      return true;
                  else
                      return false;
              }
              else
             return false;
          }
          else
          return false;
      }

    bool operator ==(const date &d)
    {
        if(_year==d._year)
        {
            if(_month==d._month)
            {
                if(_day==d._day)
                    return true;
                else
                    return false;
            }
            return false;
        }
        else
            return false;
    }
    bool operator !=(const date &d)
    {
        return !(*this==d);
    }
    bool operator >(const date &d)
    {
        if(_year>d._year)
        {
            return true;
        }
        else
        {
            if(_month>d._month)
                return true;
            else
            {
                if(_day>d._day)
                    return true;
                else
                    return false;
            }

        }

    }
    date operator +(int day)
    {
    
        int nowday=_day+day;
        while(nowday>=Getmonthday(_year,_month))
        {
            nowday=nowday-Getmonthday(_year,_month);
            if(_month==12)
            {
            
                _year++;
                _month=1;
            }
            else
            {
                
                _month++;
            }

        }
        _day=nowday;
        return (*this);
        
    }
    date  operator -(int day)
    {
        int sumday=_day;
        while(sumday<day)
        {
            sumday=sumday+Getmonthday(_year,_month);
            if(_month==1)
            {
                _month=12;
                _year--;
            }
            else
            {
                _month--;
            }
        }
        _day=sumday-day;
        return (*this);
    }
     int operator -(date const &d)
     {
         int count=0;
         if(*this>d)
         {
             while(*this!=d)
             {
                 count++;
                 *this=*this-1;
             }


         }
         else
         {
             while(*this!=d)
             {
                 count++;
                 *this=*this+1;
             }
         }
            return count;

     }

    private:
     int _year;
     int _month;
     int _day;
};
int main()
{
    int count=0;
    date A(2018,6,29);
    A.print();
    date B(2000,2,19);
    B.print();
    count=A-B;
    cout<<"Cheng hong "<<count<<" days"<<endl;
    return 0;
}

