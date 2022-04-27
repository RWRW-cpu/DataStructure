#include <iostream>
using namespace std;
#define ok 0
#define error -1;
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
    LinkList();
    ~LinkList();
    ListNode *LL_index(int i);
    int LL_get(int i);
    int LL_insert(int i, int item);
    int LL_del(int i);
    void LL_display();
    int LL_merge(LinkList *);
};
LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}
LinkList::~LinkList()
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
int LinkList::LL_insert(int i, int item)
{
    //第i个元素的前驱不存在（第i个元素的地址不存在）

    if (LL_index(i) == NULL)
        return -1;
    ListNode *p = LL_index(i);
    ListNode *s = new ListNode();
    s->data = item;
    s->next = p->next;
    p->next = s;
    len++;
    return 0;
}
ListNode *LinkList::LL_index(int i)
{
    //当前p所指向的结点
    int j = 0;
    ListNode *p = head;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    //空链表||表尾
    if (!p || j > i - 1)
        return NULL;
    return p;
}
int LinkList::LL_del(int i)
{
    //特殊情况：i个元素的前驱不存在（i个元素的地址为NULL）
    if (LL_index(i) == NULL)
        return -1;

    ListNode *p = LL_index(i);
    ListNode *q = p->next;
    p->next = q->next;
    delete q;
    len--;
    return 0;
}
int LinkList::LL_get(int i)
{
    //超过上限，或者是头结点
    if (i > len || i <= 0)
        return -1;

    ListNode *p = head;
    // p指向的当前结点
    int j = 0;
    while (p->next && j < i)
    {
        p = p->next;
        ++j;
    }
    return p->data;
}

void LinkList::LL_display()
{

    ListNode *p = head->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LL_merge(LinkList *La)
{
    LinkList *temp;
    ListNode *a = La->head->next;
    ListNode *b = head->next;
    ListNode *c = temp->head->next;
    while (a && b)
    { // 当其中一个链表为空退出循环
        if (a->data < b->data)
        { //对比两个链表的数据，按大小顺序排列
            c->next = a->next;
            c = c->next;
            a = a->next;
        }
        else
        {
            c->next = b->next;
            c = c->next;
            b = b->next;
        }
    }
    while (a)
    { // a不为空则直接把所有a结点放在新链表后面
        c->next = a->next;
        c = c->next;
        a = a->next;
    }
    while (b)
    { // b不为空则直接把所有a结点放在新链表后面
        c->next = b->next;
        c = c->next;
        b = b->next;
    }
    temp->LL_display();
}
int main()
{
    int n, m;
    LinkList list1, list2;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        list1.LL_insert(i, m);
    }
    list1.LL_display();

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        list2.LL_insert(i, m);
    }
    list2.LL_display();

    list1.LL_merge(list2);
    return 0;
}

//这是第三周的
