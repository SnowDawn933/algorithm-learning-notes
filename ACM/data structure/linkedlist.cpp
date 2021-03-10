#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next; //创一个结构体用来表示链表的节点类型
};
int main(void)
{
    struct node *head, *p, *q, *t;
    int n, a;
    scanf("%d", &n);
    head = NULL;                 //将头指针设为空
    for (int i = 1; i <= n; i++) //依次输入
    {
        scanf("%d", &a);
        p = (struct node *)malloc(sizeof(struct node)); //动态申请一个空间，来存放一个节点，并用临时指针p指向这个节点
        p->data = a;                                    //将数据存入当前节点的data域中
        p->next = NULL;                                 //设置当前节点的后继指针指向空
        if (head == NULL)
        {
            head = p; //如果这是第一个创建的节点，则将头指针指向这个节点
        }
        else
            q->next = p; //如果这不是第一个节点，就将上一个节点的后继指针指向这个节点
        q = p;           //指针p变为对于下一个节点的上一个节点
    }
    scanf("%d", &a);
    t = head; //从列表头部开始遍历
    while (t != NULL)
    {
        if (t->next == NULL || t->next->data > a)
        {
            p = (struct node *)malloc(sizeof(struct node)); //申请一个动态空间来存放要插入的数
            p->data = a;
            p->next = t->next; //新增节点的后续指针指向之前节点的后续指针所指向的节点
            t->next = p;       //当前节点的后继指针指向新增节点
            break;             //插入完成退出循环
        }
        t = t->next; //继续下一个节点
    }
    t = head; //从头输出链表中的所有数
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    return 0;
}