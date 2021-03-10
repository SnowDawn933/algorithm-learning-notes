//循环链表的删除,约瑟夫问题
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main(void)
{
    struct node *head, *p, *q, *t;
    int n, m, a;
    scanf("%d%d", &n, &m);
    head = NULL;
    for (int i = 1; i <= n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = i;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }
        if (i == n)
            p->next = head;
        q = p;
    }
    t = head;  //循环链表的删除
    int j = 1; //相当于给链表中的节点一个临时的编号
    while (1)
    {
        p = t;       //储存这一个节点
        t = t->next; //当前节点变为下一个
        j++;         //编号加一
        if (j == m)  //每到一次m
        {
            printf("%d ", t->data); //输出被删除结点中的数据
            p->next = t->next;      //当前节点的前一个节点指向当前节点的下一个节点，即删除了这个当前节点
            t = t->next;
            j = 1; //重新计数
        }
        if(t->next==p)
            break;
    }
    if(m%2==0)
        printf("%d %d", p->data, t->data);
    else
    {
        printf("%d %d", t->data, p->data);
    }
    
    return 0;
}
