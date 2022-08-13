#include<iostream>
#include<map>
#define N 26
using namespace std;
class Node
{
public:
    int p1;
    int p2;
};
int preOrder(Node *tree,int from, int to, int depth)
{
    if(from==to)
        return depth;
    if(tree[from].p1!=-1)
    {
        int ret=preOrder(tree,tree[from].p1,to,depth+1);
        if(ret!=-1)
            return ret;
    }
    if(tree[from].p2!=-1)
    {
        int ret=preOrder(tree,tree[from].p2,to,depth+1);
        if(ret!=-1)
            return ret;
    }
    return -1;
}
 
int main()
{
    int n,m;
    Node tree[N];
    while(true)
    {
        cin>>n>>m;
        if(n==0||m==0)
            break;
        for(int i=0;i<N;i++)
        {
            tree[i].p1=tree[i].p2=-1;
        }
        while(n--)
        {
            char str[4];
            cin>>str;
            if(str[1]!='-')
                tree[str[0]-'A'].p1=str[1]-'A';
            if(str[2]!='-')
                tree[str[0]-'A'].p2=str[2]-'A';
        }
        while(m--)
        {
            char str[3];
            cin>>str;
            int from=str[0]-'A';
            int to=str[1]-'A';
            int ans1=preOrder(tree,from,to,0);
            if(ans1==1)
                cout<<"child"<<endl;
            else if(ans1>=2)
            {
                for(int i=ans1;i>2;i--)
                    cout<<"great-";
                cout<<"grandchild"<<endl;
            }
            else
            {
                int ans2=preOrder(tree,to,from,0);
                if(ans2==1)
                    cout<<"parent"<<endl;
                else if(ans2>=2)
                {
                    for(int i=ans2; i>2; i--)
                        cout<<"great-";
                    cout<<"grandparent"<<endl;
                }
                else
                    cout<<' '<<endl;
            }
        }
    }
    return 0;
}