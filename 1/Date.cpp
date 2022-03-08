#include <iostream>
#include <cstring>
#include<iomanip>
using namespace std;
class Date
{
protected:
    int y;
    int m;
    int d;
public:
    Date();
    Date(int a,int b,int c):y(a),m(b),d(c){};
    int  getyear(){
        return y;
    }
    int getmonth(){
        return m;

    }
    int getday(){
        return d;
    }

    void print(){
        cout<<setfill('0')<<"Today is "<<y<<"/"<<setw(2)<<m<<'/'<<setw(2)<<d<<endl;
    }
    void addOneDay(){
        int month[12]={31,((y%4==0&&y%100!=0)||y%400==0)?29:28,31,30,31,30,31,31,30,31,30,31};
        d++;
        if(d>month[m-1]){
            d=1;
            m++;
        }
        if(m>12){
            y++;
            m=1;
        }
        cout<<setfill('0')<<"Tomorrow is "<<y<<'/'<<setw(2)<<m<<'/'<<setw(2)<<d<<endl;
    }
    ~Date(){};
};

int main()
{   
    int t,y,m,d;
    cin>>t;

    while(t--){
        cin>>y>>m>>d;
        Date p(y,m,d);
        p.print(); //今日
        p.addOneDay();//明日
    }
}