#include<iostream>
#include<string>
using namespace std;
int B;
class TreeNode
{
public:
    char data;
    TreeNode **child;
    TreeNode()
    {
        child=new TreeNode*[B];
        for(int i=0;i<B;i++)
            child[i]= NULL;
    }
};
 
class BiTreeNode
{
public:
    char data;
    BiTreeNode *firstchild,*nextsibling;
    BiTreeNode()
    {
        firstchild=NULL;
        nextsibling=NULL;
    }
    ~BiTreeNode()
    {
        delete firstchild;
        delete nextsibling;
    }
};
class Tree
{
public:
    TreeNode* root;
    Tree()
    {
        root=CreateTree();
    }
    TreeNode* CreateTree()
    {
        TreeNode *p=NULL;
        char c;
        cin>>c;
        if(c!='0')
        {
            p=new TreeNode;
            p->data=c;
            for(int k=0;k<B;k++)
                p->child[k]=CreateTree();
        }
        return p;
    }
    BiTreeNode* change(TreeNode *T)
    {
        BiTreeNode *p=NULL;
        if(T!=NULL)
        {
            p=new BiTreeNode;
            p->data=T->data;
            p->firstchild=change(T->child[0]);
            if(p->firstchild!=NULL)
            {
                BiTreeNode *q=p->firstchild;
                for(int i=1;i<B;i++)
                {
                    q->nextsibling=change(T->child[i]);
                    if(q->nextsibling!=NULL)
                        q=q->nextsibling;
                }
            }
        }
        return p;
    }
};
class BiTree
{
public:
    BiTreeNode* root;
    void getleaves(BiTreeNode* T,string parent)
    {
        string str=parent;
        if(T!=NULL)
        {
            if(T->firstchild==NULL&&T->nextsibling==NULL)
                cout<<str<<endl;
            getleaves(T->firstchild,str+ "0 ");
            getleaves(T->nextsibling,str+ "1 ");
        }
    }
    void combine(BiTreeNode** T,int N)
    {
        for(int i=0;i<N-1;i++)
            T[i]->nextsibling=T[i+1];
        root=T[0];
    }
};
 
int main()
{
    int N;
    cin>>N>>B;
    Tree* p=new Tree[N];
    BiTreeNode** Bit=new BiTreeNode* [N];   
    for(int i=0;i<N;i++)    
      Bit[i]=p[i].change(p[i].root);    
    BiTree tree;    
    tree.combine(Bit,N);    
    tree.getleaves(tree.root,"");   
    return 0;
}