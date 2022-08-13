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
    void LevelOrder()
    {
        queue<BiTreeNode*>Q;
        if(Root==NULL)
            return;
        Q.push(Root);
        while(!Q.empty())
        {
            BiTreeNode *temp=Q.front();
            cout<<temp->data;
            if(temp->Left!=NULL)
                Q.push(temp->Left);
            if(temp->Right!=NULL)
                Q.push(temp->Right);
            Q.pop();
        }
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
        tree.LevelOrder();
        cout<<endl;
    }
    return 0;
}