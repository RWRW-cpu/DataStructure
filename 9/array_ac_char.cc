#include<iostream>
using namespace std;

class BiTreeNode {
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode():LeftChild(NULL),RightChild(NULL){}
};

class BiTree {
public:
    void CreateTree(string s);
    void PreOrder();
private:
    BiTreeNode *Root;
    BiTreeNode *CreateBiTree(int pos);
    void PreOrder(BiTreeNode *t);
    string strTree;
    int len;
};

void BiTree::PreOrder() {
    PreOrder(Root);
}

void BiTree::PreOrder(BiTreeNode *t) {
    if(t)
    {
        cout<<t->data;
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

void BiTree::CreateTree(string s) {
    len = s.length();
    strTree.assign(s);
    Root = CreateBiTree(0);
}

BiTreeNode *BiTree::CreateBiTree(int pos) {
    BiTreeNode *T;
    char ch;
    if(pos>=len)
        return NULL;
    ch = strTree[pos];
    if(ch=='0')
        T = NULL;
    else {
        T = new BiTreeNode();
        T->data = ch;
        T->LeftChild = CreateBiTree(2*pos+1);
        T->RightChild = CreateBiTree(2*pos+2);
    }
    return T;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        BiTree biTree;
        biTree.CreateTree(s);
        biTree.PreOrder();
        cout<<endl;
    }
}
