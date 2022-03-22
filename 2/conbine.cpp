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
    SeqList(int n)
    {
        len = n;
        maxLen = 10000;
        list = new int[len];
        for (int i = 0; i < n; i++)
            cin >> list[i];
    }
    ~SeqList()
    {
        delete[] list;
    }
    friend SeqList combine(SeqList &s1, SeqList &s2)
    {
        SeqList s3(s1.len + s2.len);
        int i = 0, j = 0, k = 0;

        //结束  s1.len==i或s2.len==j
        while (i < s1.len && j < s2.len)
        {
            //s2的比较小
            if (s1.list[i] > s2.list[j])
            {   
                //s2赋值s3，s3和s2指向都加1
                s3.list[k++] = s2.list[j++];
            }
            //s1的比较小
            else
            {
                //s1赋值s3，s3和s1指向都加1
                s3.list[k++] = s1.list[i++];
            }
        }
        //未遍历完的加在后面
        while (i < s1.len)
        {
            s3.list[k++] = s1.list[i++];
        }
        //未遍历完的加在后面
        while (j < s2.len)
        {
            s3.list[k++] = s2.list[j++];
        }
    }
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
            cout << list[i];
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    SeqList s1(n);
    cin >> n;
    SeqList s2(n);
    SeqList s3 = combine(s1, s2);
    s3.Display();
}