#include<iostream>
#include<string>
using namespace std;
class BiTreeNode
{
public:
    char data;
    BiTreeNode *left;
    BiTreeNode *right;
    BiTreeNode()
    {
        left=NULL;
        right=NULL;
    }
    ~BiTreeNode()
    {
        delete left;
        delete right;
    }
};
class BiTree
{
    public:
    BiTreeNode  *Root;
    int pos;
    string strTree;
    //带str参数的构造函数
    BiTree(string str)
    {
        pos=0;
        strTree=str;
        Root=CreateBiTree();
    }
    //构建二叉树
    BiTreeNode *CreateBiTree(){
        BiTreeNode *T;
        char ch=strTree[pos];//对于每一个字符，都创建一个节点
        pos++;
        if(ch=='0'){
            T=NULL;
            return T;
        }
        else {
            T=new BiTreeNode();
            T->data=ch;
            T->left=CreateBiTree();
            T->right=CreateBiTree();
            return T;
        }
    }
    //先序遍历
    void PreOrder(BiTreeNode *T){
        if(T==NULL)
            return;
        cout<<T->data<<" ";
        PreOrder(T->left);
        PreOrder(T->right);
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
        tree.PreOrder(tree.Root);
        cout<<endl;
    }
}