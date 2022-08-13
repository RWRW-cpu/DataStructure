#include<iostream>
#include<string>
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
        if(ch=='#')
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
    void Pre(BiTreeNode *p)
    {
        if(p)
        {
            cout<<p->data;
            Pre(p->Left);
            Pre(p->Right);
        }
    }
    void In(BiTreeNode *p)
    {
        if(p)
        {
            In(p->Left);
            cout<<p->data;
            In(p->Right);
        }
    }
    void Post(BiTreeNode *p)
    {
        if(p)
        {
            Post(p->Left);
            Post(p->Right);
            cout<<p->data;
        }
    }
};
 
int main()
{
    string str="ABDF###E##CG###";
    BiTree tree(str);
    tree.Pre(tree.Root);

}