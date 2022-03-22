#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
class SeqList{
    protected:
    int *list;
    int len;
    int maxLen;
    public:
    SeqList(int n);
    void multiInsert(int i, int n, int *item);
    void multiDel(int i, int n);
    void Display();
    ~SeqList();
};
SeqList::SeqList(int n){
    len=n;
    maxLen=1000;
    list=new int[maxLen];
    for(int i=0;i<n;i++)
        cin>>list[i];
}
SeqList::~SeqList(){
    delete []list;
} 

void SeqList:: multiInsert(int i, int n, int *item){
    //找到最后一个元素后移n位(前面一个赋值给后面一个叫做后移),直到第i个元素
    for(int j=len-1;j>=i-1;j--){
        list[j+n]=list[j];
    }
    //找到第i个元素顺序赋值，直到第i+n-1个元素(这时候插入了n个元素)
    for(int j=i-1;j<i-1+n;j++){
        list[j]=item[j-i+1];
    }
    len+=n;
    Display();

}
void SeqList:: multiDel(int i, int n){
    //找到这个删除段中的最后一个元素的后一位前移动n位置,直到第len个元素
    for(int j=i-1+n;j<len;j++){
        list[j-n]=list[j];
    }
    len-=n;
    Display();

}
void SeqList:: Display(){
    cout<<len<<' ';
    for(int i=0;i<len;i++){
        cout<<list[i]<<' ';
    }
    cout<<endl;
}

int main(){

    int n;
    cin>>n;
    SeqList s(n);
    s.Display();
    int i,*item,t;
    cin>>i>>t;
    item=new int [t];
    for(int i=0;i<t;i++){//t和n弄混
        cin>>item[i];
    }
    s.multiInsert(i,t,item);
    cin>>i>>t;
    s.multiDel(i,t);
    delete []item;
    return 0;
}