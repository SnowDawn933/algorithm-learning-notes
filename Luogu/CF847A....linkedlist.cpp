#include <stdio.h> //如果时英文题目的话，千万不要看中文翻译，看自己去理解原版的英文，因为中文的翻译会漏掉或者意会错关键的信息
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
int main(void)
{
    struct node *head, *p; //*p是临时指针  *q是当前指针
    int n;                 //单元数
    scanf("%d", &n);
    int flag = 0;//跳出参量
    struct node *nodes[n + 10];  //每个单元
    head = NULL;                 //先将头指针初始化
    for (int i = 1; i <= n; i++) //输入每一个单元的前导和后置
    {
        nodes[i] = (struct node *)malloc(sizeof(struct node));
        nodes[i]->pre = (struct node *)malloc(sizeof(struct node));
        nodes[i]->next = (struct node *)malloc(sizeof(struct node));
        nodes[i]->data = i;
        scanf("%d%d", &nodes[i]->pre->data, &nodes[i]->next->data);
        if (head == NULL && nodes[i]->pre->data == 0) //当头指针还为空是将第一个没有前导的单元作为首位
        {
            head = nodes[i];
            flag++;
        }
    }
    p = head;                                        //p是当前指针
    while (nodes[p->data]->next->data != head->data) //当前指针的后继值不是头指针的值时进行连接
    {
        if (nodes[p->data]->next->data != 0) //当前单元的后继不是空时
        {
            p->next = nodes[p->next->data]; //进行连接
            p = nodes[p->next->data];       //改变当前单元
            flag++;
        }
        else //后继指针为空时
        {
            for (int i = 1; i <= n; i++) //遍历所有的单元寻找前导为空的单元
            {
                if (i == p->data) //跳过当前
                {
                    continue;
                }
                if (nodes[i]->pre->data == 0 && nodes[i] != head)
                {
                    nodes[i]->pre->data = p->data; //将其前导数值从0改为当前值
                    p->next = nodes[i];            //连上
                    p = nodes[i];                  //改变当前单元
                    flag++;
                    break; //找到一个连接后就跳出
                }
            }
        }
        if(flag==n)//全部链接上之后就跳出
        {
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", nodes[i]->pre->data, nodes[i]->next->data);
    }
    return 0;
}
