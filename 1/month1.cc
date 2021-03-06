/* 
题目描述
已知每个月份的英文单词如下，要求创建一个指针数组，数组中的每个指针指向一个月份的英文字符串，要求根据输入的月份数字输出相应的英文单词
1月 January
2月 February
3月 March
4月 April
5月 May
6月 June
7月 July
8月 August
9月 September
10月 October
11月 November
12月 December

输入
第一行输入t表示t个测试实例
接着每行输入一个月份的数字
依次输入t行

输出
每行输出相应的月份的字符串，若没有这个月份的单词，输出error

样例输入
3
5
11
15

样例输出
May
November
error

*/
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n;
    cin>>n;
    int t;
    char *month[13]={"0","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    while(n--){
        cin>>t;
        if(t<13&&t>0){
            for(int i=1;i<=t;i++){
                if(i==t){
                    cout<<month[i]<<endl;
                }
            }
        }
        else cout<<"error";
    }
    return 0;
}