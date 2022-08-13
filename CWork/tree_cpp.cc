#include<iostream>
#include <queue>
using namespace std;
class Node{
    public:
    char data;
    Node *left, *right;
    
    Node():left(NULL),right(NULL){}
};

class Tree{
    public:
    Node *root;
    int pos;
    string strTree;
    
    Tree(string str):pos(0),strTree(str){
        root=Create();
    }
    Node* Create(){
        char c=strTree[pos++];
        if(c=='#') return NULL;
        else {
            Node *temp=new Node();
            temp->data=c;
            temp->left=Create();
            temp->right=Create();//搞混
            return temp;
        }
    }
    void pre(Node *t){
        if(t){
            cout<<t->data;
            pre(t->left);
            pre(t->right);
        }
    }
    void level(Node *t){
        queue<Node*> q;
        if(!root) return ;//为非
        q.push(root);//不为空
        while(!q.empty()){//不为NULL
            Node *temp=q.front();
            q.pop();
            /* if(temp){
                cout<<temp->data;
                q.push(temp->left);
                q.push(temp->right);
            } */
            cout<<temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

};
int main(){
    string str="ABDF###E##CG###";
    Tree tree(str);
    tree.pre(tree.root);
    tree.level(tree.root);

}