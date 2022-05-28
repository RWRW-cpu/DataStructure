#include<iostream>
using namespace std;

//定义节点
class circle_node
{
public:
	int data;
	int L1;
	int L2;
	circle_node* next1;
	circle_node* next2;
};
//定义循环链表
class circle_list
{
public:
	circle_node* head;
	int size;
};
 
//链表初始化
circle_list* list_init()
{
	circle_list* L =new circle_list;
	L->size=0;
	L->head=new circle_node;
	L->head->data=404;
	L->head->next1=L->head;  //头指针初始指向自己
	L->head->next2=L->head;		//第二个指针初始指向自己
	return L;
}
//插入链表
void list_insert1(circle_list *L,int pos,int data)
{
	//创建新指针new_node;
	circle_node* new_node=new circle_node;
	new_node->data=data;
	new_node->next1=NULL;
	//根据位置查找pos的前一个节点
	circle_node* pcurrent=L->head;
	for (int i = 0; i < pos; i++)
	{
		pcurrent=pcurrent->next1;
	}
	//将new_node插入
	new_node->next1=pcurrent->next1;
	pcurrent->next1=new_node;
	L->size++;
}

void list_insert2(circle_list *L,int pos,int data)
{
	//创建新指针new_node;
	circle_node* new_node=new circle_node;
	new_node->data=data;
	new_node->next2=NULL;
	//根据位置查找pos的前一个节点
	circle_node* pcurrent=L->head;
	for (int i = 0; i < pos; i++)
	{
		pcurrent=pcurrent->next2;
	}
	//将new_node插入
	new_node->next2=pcurrent->next2;
	pcurrent->next2=new_node;
	L->size++;
}

//打印链表,按num自由指定打印数据个数
void list_print1(circle_list *L,int num)
{
	circle_node* pcurrent=L->head->next1;
	for (int i = 1; i <=num; i++)
	{
        if (pcurrent==L->head)
		{
			pcurrent=L->head->next1;
		}
		cout<<pcurrent->data<<"\t";
		pcurrent=pcurrent->next1;
	}
	cout<<endl;
}


//打印链表,按num自由指定打印数据个数
void list_print2(circle_list *L,int num)
{
	circle_node* pcurrent=L->head->next2;
	for (int i = 1; i <=num; i++)
	{
        if (pcurrent==L->head)
		{
			pcurrent=L->head->next2;
		}
		cout<<pcurrent->data<<"\t";
		pcurrent=pcurrent->next2;
	}
	cout<<endl;
}

int main()
{
	//创建单向循环链表
	circle_list* L=list_init();
	//插入数据0~9
	for (int i = 0; i < 10; i++)
	{
		list_insert1(L,i,1);
	}
	cout<<"链表中数据为："<<endl;
	list_print1(L,10);
	cout<<"链表中2倍数据为："<<endl;
	list_print2(L,10);
	system("pause");
	return 0;
}