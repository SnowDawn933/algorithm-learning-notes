#include <stdio.h>
struct line
{
    int data[1000];//数组一定要开大一点
    int head;
    int tail;
};
struct shed
{
    int data[20];
    int top;
};
int main(void)
{
    struct line q1, q2;
    struct shed s;
    int book[10], t;
    q1.head = 1; //初始化栈和队列
    q1.tail = 1;
    q2.head = 1;
    q2.tail = 1;
    s.top = 0;
    for (int i = 1; i <= 10; i++)
    {
        book[i] = 0;
    }
    for (int i = 1; i <= 6; i++)
    {
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
    for (int i = 1; i <= 6; i++)
    {
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }
    while (q1.head < q1.tail && q2.head < q2.tail)
    {
        t = q1.data[q1.head];
        if (book[t] == 0)
        {
            q1.head++;
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        }
        else
        {
            q1.head++;
            q1.data[q1.tail] = t;
            q1.tail++;
            while (s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;
                q1.data[q1.tail] = s.data[s.top];
                s.top--;
                q1.tail++;
            }
            book[s.data[s.top]] = 0;
            q1.data[q1.tail] = s.data[s.top];
            s.top--;
            q1.tail++;
        }
        if (q1.head == q1.tail)
            break;
        t = q2.data[q2.head];
        if (book[t] == 0)
        {
            q2.head++;
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        }
        else
        {
            q2.head++;
            q2.data[q2.tail] = t;
            q2.tail++;
            while (s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;
                q2.data[q2.tail] = s.data[s.top];
                s.top--;
                q2.tail++;
            }
            book[s.data[s.top]] = 0;
            q2.data[q2.tail] = s.data[s.top];
            s.top--;
            q2.tail++;
        }
    }
    if (q2.head == q2.tail)
    {
        printf("小哼 win\n");
        printf("小哼当前手中的牌是");
        for (int i = q1.head; i <= q1.tail - 1; i++)
        {
            printf(" %d", q1.data[i]);
        }
        if (s.top > 0)
        {
            printf("\n桌上的牌是");
            for (int i = 1; i > s.top; i++)
            {
                printf(" %d", s.data[i]);
            }
        }
        else
        {
            printf("\n桌子上己经没有牌了");
        }
    }
    else
    {
        printf("小哈 win\n");
        printf("小哈当前手中的牌是");
        for (int i = q2.head; i <= q2.tail - 1; i++)
        {
            printf(" %d", q2.data[i]);
        }
        if (s.top > 0)
        {
            printf("\n桌上的牌是");
            for (int i = 1; i <= s.top; i++)
            {
                printf(" %d", s.data[i]);
            }
        }
        else
        {
            printf("\n桌子上己经没有牌了");
        }
    }
    return 0;
}