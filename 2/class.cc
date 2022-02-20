#include <iostream>
#include <cstring>
using namespace std;

void SqeInsert(int i,int item,int size,int *p){//
    for(int j=size;j>i-1;j--){//从最后一个的后一个位序开始，直到这个位序
        p[j]=p[j-1];
    }//最后一步是j=2,j--,判断1>0,p[j-1]=1,p[j]=1,j=1,i=1;先j--，然后判断0>0不通过，跳出循环
    p[i-1]=item;//与上面的a[j-1]对应
    size++;
    for(int j=0;j<size;j++){
        cout<<p[j]<<" ";
    }
    cout<<endl;
}
void Sqedelete(int i,int size,int *p){
    for(int j=i-1;j<size-1;j++){
        p[j]=p[j+1];//与上面SqeInsert的a[i-1]对应
    }
    size--;
    for(int j=0;j<size;j++){
        cout<<p[j]<<" ";
    }
}
int main()
{
    int i;
    int item;
    cin>>i>>item;
    int size=13;
    int a[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    int *p=a;
    SqeInsert(i,item,size,p);
    Sqedelete(i,size,p);

}