/* 中缀转后缀波兰式 */
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool judge(char top, char s)
{
    //栈相同
    if ((top == '+' || top == '-') && (s == '-' || s == '+'))
        return true;
    if ((top == '*' || top == '/') && (s == '*' || s == '/'))
        return true;
    //栈高
    if ((top == '*' || top == '/') && (s == '-' || s == '+'))
        return true;
    //栈低，压入栈中
    if ((top == '+' || top == '-') && (s == '*' || s == '/'))
    {
        return false;
    }
    // b*(c-d)   s==(   top==( 压栈
    if (top == '(' || s == '(')
        return false;
    //放行到下一个else if
    if (s == ')')
        return true;
}

string into(string s1)
{
    stack<char> sk;
    string s2 = s1;
    int j = 0;
    for (int i = 0; i < (int)s1.length(); i++)
    {
        //运算符
        if (s1[i] == '*' || s1[i] == '/' || s1[i] == '+' || s1[i] == '-' || s1[i] == ')' || s1[i] == '(')
        {
            //栈空一定压入栈中//或者栈低,栈顶为括号或者
            if (sk.empty() || !judge(sk.top(), s1[i]))
            {
                sk.push(s1[i]);
            }
            //解决括号问题
            else if (s1[i] == ')')
            {
                while (sk.top() != '(')
                {
                    s2[j] = sk.top();
                    // cout<<s2[j]<<' ';
                    j++;
                    s2[j] = ' ';
                    j++;
                    sk.pop();
                }
                sk.pop();
            }
            //已经遇不到括号了
            //非空且（栈高或者栈相等)
            else
            {
                while (judge(sk.top(), s1[i]))
                {
                    s2[j] = sk.top();
                    // cout << s2[j] << ' ';
                    j++;
                    s2[j] = ' ';
                    j++;
                    sk.pop();
                    if (sk.empty() || !judge(sk.top(), s1[i]))
                    {
                        sk.push(s1[i]);
                        break;
                    }
                }
            }
        }
        //操作数
        else
        {
            s2[j] = s1[i];
            // cout << s2[j] << ' ';
            j++;
            //s2[j] = ' ';
            //j++;
        }
    }
    //最后剩余的运算符23+(34*45)/(5+7)
    while (!sk.empty())
    {
        s2[j] = sk.top();
        // cout << s2[j] << ' ';
        j++;
        s2[j] = ' ';
        j++;
        sk.pop();
    }
    //以防乱码
    s2[j] = '\0';
    return s2.c_str();
}

int main()
{
    string str1 = {"23+(34*45)/(5+7)"};
    string str2 = into(str1);
    cout << str2;
}