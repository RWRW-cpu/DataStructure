/* 
【25分】A. DS顺序表--类实现
题目描述

用C++语言和类实现顺序表

属性包括：数组、实际长度、最大长度（设定为1000）

操作包括：创建、插入、删除、查找

类定义参考 

输入

第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据
第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置


输出

数据之间用空格隔开

第1行输出创建后的顺序表内容，包括顺序表实际长度和数据

每成功执行一次操作（插入或删除），输出执行后的顺序表内容

每成功执行一次查找，输出查找到的数据

如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出顺序表内容
输入:
6 11 22 33 44 55 66
3 777
1 888
1
9
0
5

输出:
6 11 22 33 44 55 66 
7 11 22 777 33 44 55 66 
8 888 11 22 777 33 44 55 66 
7 11 22 777 33 44 55 66 
error
error
44

*/


#include<iostream>
using namespace std;

#define ok 0
#define error -1//多的用指针const char *a[]={};

class SeqList{
	private: 
		int *list;
		int maxsize;
		int size;
	public:
		SeqList(){//构造函数
			maxsize = 1000;
			size =  0;
			list = new int[maxsize];
		}
		~SeqList(){//new和delete
			delete []list;
		}
		int push_back(int i){
			list[size]=i;
			size++;
		}
        //以下定义
        //位置是查询的序列号，位序是位置的-1，即数组里面的序列号
		int list_del(int i){//和insert类似
			if(i<=0||i>size){//查询错误情况：没有这个位置
				cout<<"error"<<endl;
				return 0;
			}
			for(int j = i-1; j < size-1 ;j++){//从这个位序开始，直到最后一个位序
				list[j]=list[j+1];//后一个的值赋给前一个
			}
			size--;//大小变小
			list_display();
		}
		int list_insert(int i,int item){
			if(i<0||i>size+1){//查询错误情况：不能增加的位置
				cout<<"error"<<endl;
				return 0;
			}
			for(int j = size; j >i-1 ;j--){//从最后一个的后一个的位序开始，直到这个位序
				list[j]=list[j-1];//前一个赋给后一个
			}
			list[i-1]=item;//值赋给这个位序
			size++;//变大
			list_display();
		}
		int list_get(int i){
			if(i<=size&&i>0){
				cout<<list[i-1]<<endl;
			}else
				cout<<"error"<<endl;
		}
		void list_display(){
			cout<<size<<" ";
			for(int i=0;i<size;i++){
				cout<<list[i]<<" ";
			}
			cout<<endl;
		}
		
};

int main(){
	int n;//n个位置
	int a;//位序
	int item;//位序对应的数
	cin >> n;
	SeqList s;//SeqList类
	for(int i=0;i<n;i++){//存入数据
		cin>>a;
		s.push_back(a);
	}
	s.list_display();//输出顺序表
	//插入
	cin>>a>>item;
	s.list_insert(a,item);
	cin>>a>>item;
	s.list_insert(a,item);
	//删除
	cin>>a;
	s.list_del(a);
	cin>>a;
	s.list_del(a);
	cin>>a;
	//查找
	s.list_get(a);
	cin>>a;
	s.list_get(a);
	return 0;
} 
