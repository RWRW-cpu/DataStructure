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
	int n;
	int a;//位序
	int item;//位序对应的数
	cin >> n;
	SeqList s;//SeqList类
	for(int i=0;i<n;i++){
		cin>>a;
		s.push_back(a);
	}
	s.list_display();
	cin>>a>>item;
	s.list_insert(a,item);
	cin>>a>>item;
	s.list_insert(a,item);
	cin>>a;
	s.list_del(a);
	cin>>a;
	s.list_del(a);
	cin>>a;
	s.list_get(a);
	cin>>a;
	s.list_get(a);
	return 0;
} 
