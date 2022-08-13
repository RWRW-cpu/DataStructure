#include<iostream>
#include<string>
#include<queue>
using namespace std;
class BiTreeNode
{
public:
    char data;
    BiTreeNode *Left;
    BiTreeNode *Right;
    BiTreeNode()
    {
        Left=NULL;
        Right=NULL;
    }
    ~BiTreeNode()
    {
        delete Left;
        delete Right;
    }
};
  
class BiTree
{
public:
    BiTreeNode *Root;
    int pos;
    string strTree;
    BiTree(string str)
    {
        pos=0;
        strTree=str;
        Root=CreateBiTree();
    }
    BiTreeNode *CreateBiTree()
    {
        char ch=strTree[pos];
        pos++;
        if(ch=='0')
        {
            return NULL;
        }
        else
        {
            BiTreeNode *T;
            T=new BiTreeNode();
            T->data=ch;
            T->Left=CreateBiTree();
            T->Right=CreateBiTree();
            return T;
        }
    }
    int countleaves()
    {
        int count=0;
        queue<BiTreeNode*>Q;
        if(Root==NULL)
            return 0;
        Q.push(Root);
        while(!Q.empty())
        {
            int flag=0;
            BiTreeNode *temp=Q.front();
            if(temp->Left!=NULL)
            {
                flag++;
                Q.push(temp->Left);
            }
            if(temp->Right!=NULL)
            {
                flag++;
                Q.push(temp->Right);
            }
            Q.pop();
            if(flag==0)
                count++;
        }
        return count;
    }
};
  
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        BiTree tree(str);
        cout<<tree.countleaves()<<endl;
    }
    return 0;
}