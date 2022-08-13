#include <iostream>
#include <string>
#include <queue>
using namespace std;
class BiTreeNode
{
public:
    char data;
    BiTreeNode *Left;
    BiTreeNode *Right;
    BiTreeNode()
    {
        Left = NULL;
        Right = NULL;
    }
};
class BiTree
{
public:
    BiTreeNode *Root;
    int pos; //记录当前节点的位置
    string strTree;
    BiTree(string str)
    {
        pos = 0;
        strTree = str;
        Root = CreateBiTree();
    }
    BiTreeNode *CreateBiTree()
    {
        char ch = strTree[pos];
        pos++;
        if (ch == '0')
        {
            return NULL;
        }
        else
        {
            BiTreeNode *T = new BiTreeNode();
            T->data = ch;
            T->Left = CreateBiTree();
            T->Right = CreateBiTree();
            return T;
        }
    }
    void Pre(BiTreeNode *p)
    {
        if (p)
        {
            cout << p->data;
            Pre(p->Left);
            Pre(p->Right);
        }
    }
    void In(BiTreeNode *p)
    {
        if (p)
        {

            In(p->Left);
            cout << p->data;
            In(p->Right);
        }
    }
    void Post(BiTreeNode *p)
    {
        if (p)
        {

            Post(p->Left);

            Post(p->Right);
            cout << p->data;
        }
    }
    void Level()
    {
        queue<BiTreeNode *> Q;
        if (Root == NULL)
            return;
        Q.push(Root);
        while (!Q.empty())
        {
            BiTreeNode *temp = Q.front();
            cout << temp->data;
            if (temp->Left)
                Q.push(temp->Left);
            if (temp->Right)
                Q.push(temp->Right);
            Q.pop();
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
    
        string str;
        cin >> str;
        BiTree tree(str);
        /* tree.Pre(tree.Root);
        cout << endl;
        tree.In(tree.Root);
        cout << endl;
        tree.Post(tree.Root);
        cout << endl; */
        tree.LevelOrder();
        tree.Level();
    
    return 0;
}