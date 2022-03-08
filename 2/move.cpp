#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
int len;
void Left(int *List, int t)
{
    while (t--)
    {
        int temp = List[0];
        for (int i = 1; i < len; i++)
        {
            List[i - 1] = List[i];
        }
        List[len - 1] = temp;
    }

    for (int i = 0; i < len; i++)
    {
        cout << List[i] << ' ';
    }
    cout << endl;
}
void Right(int *List, int t)
{
    while (t--)
    {
        int temp = List[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            List[i + 1] = List[i];
        }
        List[0] = temp;
    }
    for (int i = 0; i < len; i++)
    {
        cout << List[i] << ' ';
    }
}
int main()
{
    cin >> len;
    int *List = new int[1000];
    for (int i = 0; i < len; i++)
    {
        cin >> List[i];
    }
    for (int i = 0; i < len; i++)
    {
        cout << List[i] << ' ';
    }
    cout<<endl;
    int gg, t;
    int test=2;
    while (test--)
    {
        cin>>gg;
        cin >> t;
        if (gg == 0)
            Left(List, t);
        else
            Right(List, t);
    }
    return 0;
}