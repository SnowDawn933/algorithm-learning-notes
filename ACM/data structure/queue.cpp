//输入一串数字，将其第一位删除，第二位移动至末尾。第三位删除，第四位移至末尾，一次类推，直到全部被删除。
//输出被删除的数
#include <stdio.h>
struct line//创建一个队列
{
    int data[101];
    int head;
    int tail;
};

int main(void)
{
    struct line q;
    q.head = 1;//队列的头和尾
    q.tail = 1;
    for (int i = 1; i <= 9; i++)
    {
        scanf("%d", &q.data[q.tail]);//将要解密的数字串输入
        q.tail++;
    }
    while (q.head < q.tail)//直到删完
    {
        printf("%d ", q.data[q.head]);
        q.head++;//将首位删去，指到第二位
        q.data[q.tail] = q.data[q.head];//第二位到末尾去
        q.tail++;//相应的末尾就试下一位了
        q.head++;//再把第二位删了
    }
    return 0;
}
