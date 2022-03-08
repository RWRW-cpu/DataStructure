#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
class SeqList
{
protected:
    int *list;
    int len;
    int maxLen;

public:
    SeqList(){};
    SeqList(int n)
    {
        len = n;
        maxLen = 10000;
        list = new int[len];
    }
    void init(){
         for (int i = 0; i < len; i++)
            cin >> list[i];
    }
    ~SeqList()
    {
        delete[] list;
    }

    friend SeqList combine(SeqList &s1, SeqList &s2);

    SeqList(const SeqList &s)
    {
        len = s.len;
        for (int i = 0; i < len; i++)
        {
            list[i] = s.list[i];
        }
    }
    void Display()
    {
        cout << len << ' ';
        for (int i = 0; i < len; i++)
        {
            cout << list[i]<<' ';
        }
        cout << endl;
    }
};

SeqList combine(SeqList &s1, SeqList &s2)
{
    SeqList s3(s1.len + s2.len);
    int i = 0, j = 0, k = 0;

    //结束  s1.len==i或s2.len==j
    while (i < s1.len && j < s2.len)
    {
        if (s1.list[i] > s2.list[j])
        {
            s3.list[k++] = s2.list[j++];
        }
        else
        {
            s3.list[k++] = s1.list[i++];
        }
    }
    while (i < s1.len)
    {
        s3.list[k++] = s1.list[i++];
    }
    while (j < s2.len)
    {
        s3.list[k++] = s2.list[j++];
    }

    return s3;
}
int main()
{
    int n;
    cin >> n;
    SeqList s1(n);
    s1.init();
    cin >> n;
    SeqList s2(n);
    s2.init();
    SeqList s3 = combine(s1, s2);
    s3.Display();
}