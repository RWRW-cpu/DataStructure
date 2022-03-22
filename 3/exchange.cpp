#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() { next = NULL; }
};
class LinkList
{
public:
    ListNode *head;
    int len;
    LinkList()
    {
        head = new ListNode();
        len = 0;
    }
    ~LinkList()
    {
        ListNode *p, *q;
        p = head;
        while (p != NULL)
        {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }
    ListNode *index(int i)
    {
        //不合法的i返回null
        if(i<0) return NULL;
        //p指针指向head结点
        ListNode *p = head;
        int j = 0;
        //while循环后，p指针指向i，一共i次循环
        while (p && j < i)
        {
            p = p->next;
            ++j;
        }
        //当i超过len时返回的也是null
        return p;
    }
    void display()
    {
        ListNode *p = head->next;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    int insert(int i, int m)
    {
        //如果i是0或者负数，直接排除
        if (i<1)
            return -1;
        ListNode *p = head;
        int j = 0;
        //执行完成while ，p指针指向i-1个元素
        while (p && j < i - 1)
        {
            p = p->next;
            ++j;
        }
        //如果执行完上面代码，p指向null，则说明i>len
        if(p==NULL){
            return -1;
        }
        ListNode *s = new ListNode();
        s->data = m;
        s->next = p->next;
        p->next = s;
        len++;
        return 0;
    }
    int swap(int a1, int b1)
    {
        if(a1<1||b1<1||a1>len||b1>len){
            cout<<"error";
            return -1;
        }
        ListNode *t1 = head;
        int j = 0;
        while (t1 && j < a1 - 1)
        {
            t1 = t1->next;
            ++j;
        }
        //cout<<t1->data<<endl;

        ListNode *t2 = head;
        j = 0;
        while (t2 && j < b1 - 1)
        {
            t2 = t2->next;
            ++j;
        }
        //cout<<t2->data<<endl;

        ListNode *a=t1->next;
        ListNode *b=t2->next;

        ListNode *temp = b->next;
        t1->next=b;
		b->next=a->next;
		t2->next=a;
		a->next=temp;

        display();
        return 0;

    }
};

int main()
{
    int n, m, i;
    LinkList list;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> m;
        list.insert(i, m);
    }
    list.display();
    ListNode *s=list.index(3);
    cout<<s->next->data<<endl;

    /* int x1,x2;
    cin>>x1>>x2;
    list.swap(x1,x2);
    
    cin>>x1>>x2;
    list.swap(x1,x2); */
    
    return 0;
}
/*
3 1 2 3
2 3

 */