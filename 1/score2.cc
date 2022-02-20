#include <iostream>
using namespace std;
int main()
{
    int t;   //t个实例RW
    cin>>t;
    int n;
    int middle;
    int index;
    while(t--){
        cin>>n;
        int *p=new int [n];
        middle=n/2;

        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        cin>>index;
        cout<<p[middle-1]<<p[middle+1];
        cout<<p[index-1]; 


    }
    
}
