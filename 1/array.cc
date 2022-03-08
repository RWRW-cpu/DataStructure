#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
class Point
{
private:
    double x,y;
public:
    Point(){
        cout<<"Constructor."<<endl;
    }
    Point(double a,double b):x(a),y(b){};
    void set(double a,double b){
        x=a;
        y=b;
    }
    double GetX(){
        return x;
    }
    double GetY(){
        return y;
    }
    double Getdistance(const Point &p){
        double distance;
        distance=sqrt(pow(x-p.x,2)+pow(y-p.y,2));
        return distance;
    }

    ~Point(){
        cout<<"Distructor."<<endl;
    }
};




int main(){
    double t,a,b;   //t个实例RW
    cin>>t;
    double max;
    int n;
    double index1,index2;
    while(t--){
        max=0;
        index1=0;
        index2=0;
       cin>>n;
       Point *p=new Point[n];
       for(int  i=0;i<n;i++){
           cin>>a>>b;
           p[i].set(a,b);
       }
       for(int j=0;j<n-1;j++){
            for(int i=1;i<n;i++){
                if(i==j) continue;
                if(p[j].Getdistance(p[i])>max){
                    max=p[j].Getdistance(p[i]);
                    index1=j;
                    index2=i;
                }
            }           
       }
        
       cout<<"The longeset distance is "<<fixed<<setprecision(2)<<max;
       cout<<",between p["<<setprecision(0)<<index1<<"] and p["<<index2<<"]."<<endl;
       delete []p;//别忘记咯
    }
}