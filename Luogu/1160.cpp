#include <stdio.h>
struct node
{
    int id;
    struct node *pre = NULL;
    struct node *next = NULL;
};
int flag[100010];//标记是否被抽出
int main(void)
{
    int n, num, w, m, a;
    scanf("%d", &n);                //输入人数
    struct node s[n + 10], head, *p;//申请单元
    head = s[1];//首位
    s[1].id = 1;
    for (int i = 2; i <= n; i++)//从第二个同学开始往里面插入
    {
        s[i].id = i;
        scanf("%d%d", &num, &w);//插入到那个数的哪边
        if (w == 0 && s[num].pre == NULL)//如果是左边且那个数的前导指针是空
        {
            s[num].pre = &s[i];//进行双向连接
            s[i].next = &s[num];
        }
        else if (w == 0 && s[num].pre != NULL)//左边且前导不为空
        {
            s[num].pre->next = &s[i];//进行插入操作
            s[i].next = &s[num];
            s[i].pre = s[num].pre;
            s[num].pre = &s[i];
        }
        else if (w == 1 && s[num].next != NULL)//插入右边且后继不为零
        {
            s[num].next->pre = &s[i];//进行插入
            s[i].next = s[num].next;
            s[i].pre = &s[num];
            s[num].next = &s[i];
        }
        else if (w == 1 && s[num].next == NULL)//插入右边且后继为零
        {
            s[num].next = &s[i];
            s[i].pre = &s[num];
        }
    }
    scanf("%d", &m);//输入删除操作的次数
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a);//删除那一个数
        if (flag[a] == 0)//如果还没有被删除
        {
            if (s[a].pre == NULL)//若前导为空
            {
                s[a].next->pre = NULL;//进行删除
                s[a].next = NULL;
            }
            else if (s[a].next == NULL)//若后继为空
            {
                s[a].pre->next = NULL;//进行删除
                s[a].pre = NULL;
            }
            else
            {
                s[a].pre->next = s[a].next;
                s[a].next->pre = s[a].pre;
                s[a].pre = NULL;
                s[a].next = NULL;
            }
            flag[a]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i].pre == NULL && s[i].next != NULL)
        {
            p = &s[i];
            printf("%d ", p->id);
            while (1)
            {
                p = p->next;
                printf("%d ", p->id);
                if (p->next == NULL)
                    break;
            }
        }
    }
    return 0;
}