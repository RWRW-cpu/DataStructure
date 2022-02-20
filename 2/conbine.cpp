#include <iostream>
using namespace std;

class SeqList{
    int *list;
    int len;
    int maxLen;
public:
    SeqList(int n);
    ~SeqList();
    void Init();
    SeqList combineList(SeqList li); //注意，这里要传引用，不然传进去的对象会被析构，list内存会被重复delete
    /* 不传就报错
    conbine.cpp:26:9: error: prototype for 'SeqList SeqList::combineList(SeqList&)' does not match any in class 'SeqList'
    SeqList SeqList::combineList(SeqList &li) {
            ^~~~~~~
    conbine.cpp:12:13: error: candidate is: SeqList SeqList::combineList(SeqList)
        SeqList combineList(SeqList li); //注istelete
                ^~~~~~~~~~~    
     */

    void outPut();
};

SeqList::SeqList(int n) {
    len = n;
    maxLen = 1000;
    list = new int[maxLen];
}

SeqList::~SeqList() {
    delete []list;
}

SeqList SeqList::combineList(SeqList &li) {
    SeqList combine(len+li.len);
    int i=0,j=0,k=0;
    while (i<len && j<li.len)
    {
        if(list[i]<li.list[j])
        {
            combine.list[k] = list[i];
            i++;
        }
        else
        {
            combine.list[k] = li.list[j];
            j++;
        }
        k++;
    }

    while (i<len)
    {
        combine.list[k] = list[i];
        i++,k++;
    }
    while (j<li.len)
    {
        combine.list[k] = li.list[j];
        j++,k++;
    }

    return combine;
}

void SeqList::Init() {
    for(int i=0;i<len;i++)
        cin>>list[i];
}

void SeqList::outPut() {
    cout<<len<<' ';
    for(int i=0;i<len;i++)
        cout<<list[i]<<' ';
    cout<<endl;
}


int main()
{
    int n,m;
    cin>>n;
    SeqList firstList(n);
    firstList.Init();
    cin>>m;
    SeqList secondList(m);
    secondList.Init();
    SeqList thirdList = firstList.combineList(secondList);
    thirdList.outPut();
    return 0;
}
