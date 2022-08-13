#include <iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    queue<char>q;
    if(q.empty())
    q.push('3');
    else
    q.pop();
    while(!q.empty()){
        char temp=q.back();
        cout<<temp<<endl;
        q.pop();
    }
    
    


}