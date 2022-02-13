#include <iostream>
using namespace std;
int main()
{
    int t,n,i,index;
    int *a,*p;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=new int[n];//开辟动态数组
		for(i=0;i<n;i++)
            cin>>a[i];
        cin>>index;
		p=a+n/2;//p指向中间的数
        p--;
        cout<<*p<<" ";
        p++;p++;
        cout<<*p<<endl;
        p=a+index-1;//p指向第index-1的数；
        cout<<*p<<endl;
        delete []a;//!!!开辟了动态数组后记得撤销
    }
    return 0;
}
