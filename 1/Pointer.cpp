#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    char ch;
    while(t--){
        cin>>ch>>n;
        if(ch=='C'){
            char *p=new char[n];
            for(int i=0;i<n;i++){
                cin>>p[i];
            }
            char max=p[0];
            for(int i=1;i<n;i++){
                if(p[i]>max){
                    max=p[i];
                }
            }
            cout<<max<<endl;
            delete []p;
            
        }
        if(ch=='I'){
            int *p=new int [n];
            for(int i=0;i<n;i++){
                cin>>p[i];
            }
            int sum=0;
            for(int i=0;i<n;i++){
                sum=sum+p[i];
            }
            double average=double(sum)/n;
            cout<<average<<endl;
            delete []p;
        }
        if(ch=='F'){
            double *p=new double[n];
            for(int i=0;i<n;i++){
                cin>>p[i];
            }
            double min=p[0];
            for(int i=1;i<n;i++){
                if(p[i]<min){
                    min=p[i];
                }
            }
            cout<<min<<endl;
            delete []p;

        }
    }
}