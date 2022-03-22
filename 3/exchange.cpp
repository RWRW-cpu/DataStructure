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

        ListNode *p = head;
        int j = 0;
        while (p && j < i)
        {
            p = p->next;
            ++j;
        }
        if (!p || j > i )
            return NULL;
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
       /*  //判断i合不合法（如果i是大于len的，则return -1）
        if (index(i) == NULL)
            return -1; */
        ListNode *p = head;
        int j = 0;
        while (p && j < i - 1)
        {
            p = p->next;
            ++j;
        }
        ListNode *s = new ListNode();
        s->data = m;
        s->next = p->next;
        p->next = s;
        len++;
        return 0;
    }
    void swap(int a1, int b1)
    {
        /* ListNode *t1 = index(a1-1);
        ListNode *a= index(a1);
        cout<<a->data<<endl;

        ListNode *t2 = index(b1 - 1);
        ListNode *b = index(b1);
        cout<<b->data<<endl; */

        ListNode *t1 = head;
        int j = 0;
        while (t1 && j < a1 - 1)
        {
            t1 = t1->next;
            ++j;
        }
        cout<<t1->data<<endl;

        ListNode *t2 = head;
        j = 0;
        while (t2 && j < b1 - 1)
        {
            t2 = t2->next;
            ++j;
        }
        cout<<t2->data<<endl;

        ListNode *a=t1->next;
        ListNode *b=t2->next;

        ListNode *temp = b->next;
        t1->next=b;
		b->next=a->next;
		t2->next=a;
		a->next=temp;
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
    int x1,x2;
    cin>>x1>>x2;
    list.swap(x1,x2);
    list.display();
    ListNode*s= list.index(3);
    cout<<s->data<<endl;

    
    return 0;
}
/*
3 1 2 3
2 3

 */