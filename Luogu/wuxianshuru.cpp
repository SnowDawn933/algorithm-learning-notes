//简单选择排序：对于一个序列A中的所有元素，令i从1到n枚举，进行n趟操作，每趟从待排序的部分【i，n】中
//选择最小的将其与元素啊【i】交换，全部遍历后就可以得到一个有序的数组。
#include <stdio.h>
int a[1005];
void seclection()
{
    for (int i = 1; i <= n; i++)
    {
        int k = i; //k为要排列的序列中最小的数的下标
        for (int j = i; i <= n; i++)
        {
            if (a[j] < a[k])
            {
                k = j; //筛选出最小
            }
        }
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}
int n;
int main(void)
{

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("d", &a[i]);
    }
    selection();
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}
