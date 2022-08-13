#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int i, n;
    cin>>n;
    char ch;
    string temp;
    queue<string> f, m;
    for(i=0; i<n; i++)
    {
        cin>>temp>>ch;
        if(ch=='F')
            f.push(temp);
        else
            m.push(temp);
    }
    string temp1, temp2;
    while(!f.empty() && !m.empty())
    {
        temp1 = f.front();
        temp2 = m.front();
        f.pop();
        m.pop();
        cout<<temp1<<' '<<temp2<<endl;
    }
    if(!f.empty())
        cout<<"F:"<<f.size()<<endl;
    if(!m.empty())
        cout<<"M:"<<m.size()<<endl;
}
