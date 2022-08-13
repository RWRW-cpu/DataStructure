#include<iostream>
#include<string>
using namespace std;
class BiTree
{
public:
    int *Tree;
    int number;
    BiTree(int n,int *c)
    {
        number=n;
        Tree=new int[number];
        for(int i=0;i<number;i++)
        {
            Tree[i]=c[i];
        }
    }
    void Pre(int i)
    {
        if(i<number)
        {
            if(Tree[i]!=0)
            {
                cout<<Tree[i]<<" ";
                Pre(2*i+1);
                Pre(2*i+2);
            }
        }
    }
};
 
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int number;
        cin>>number;
        int *c=new int[number];
        for(int i=0;i<number;i++)
            cin>>c[i];
        BiTree T(number,c);
        T.Pre(0);
        cout<<endl;
    }
    return 0;
}