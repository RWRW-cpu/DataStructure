/* 【10分】B. 成绩查询（指针运算）
题目描述

已知一组学生成绩，然后根据输入的序号查询成绩

要求：

1. 使用一个整数数组存储学生成绩

2. 使用一个指针指向数组中间元素

3. 使用++和--运算符，求出数组中间元素的前一个成绩和后一个成绩

4. 输入一个序号，然后计算这个序号的元素和中间元素的距离，然后使用指针去访问

例如有11个学生，指针指向中间的学生也就是第6个学生，若输入序号3，即查询第3个学生的成绩，第3和第6之间距离为3，那么指针应该怎么运算呢？？？

5. 整个程序除了输入时可以使用数组下标，其他部分都不能使用，都必须使用指针进行访问，且只能定义一个指针变量。


输入

第一行输入t表示有t个测试实例

第二行先输入n，表示有n个学生，然后再输入n个成绩（正整数）

第三行输入1个序号，表示要查询成绩的学生的序号。

依次输入t个实例

按自然意义，序号是从1开始计算

提示：在数组中是从........


输出

对于每个测试实例：

第一行输出数组中间元素的前一个成绩和后一个成绩(若为偶数，取中间右边的数为中间数）

第二行根据序号输出1个成绩 */

/* 输入
2
7 66 99 88 44 77 33 11
2
11 60 80 50 20 90 35 70 40 10 95 30
9

输出
88 77
99
90 70
10
 */

#include <iostream>
using namespace std;
int main()
{
    int t;   //t个实例RW
    cin>>t;
    int n;
    int middle;
    int index;
    while(t--){
        cin>>n;
        int *p=new int [n];
        middle=n/2;

        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        cin>>index;
        cout<<p[middle-1]<<" "<<p[middle+1]<<endl;
        cout<<p[index-1]<<endl; 
    }
    
}