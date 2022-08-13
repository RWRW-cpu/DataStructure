#include <iostream>
#include<stack>
using namespace std;

int main(){
    stack<char>s;
    
    if(s.empty())
    s.push('3');
    else
    s.pop();
    while(!s.empty()){
        char p=s.top();
        cout<<p<<endl;
        s.pop();
    }


}