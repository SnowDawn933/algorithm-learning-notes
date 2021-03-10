// 直接插入排序：
//选择第一个数字作为有序数列的初始，将其他的数字依次和有序数列进行比较，找到属于自已的有序位置之后就插进去
#include <cstdio>
void insertsort(int n);
int a[1005];
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    insertsort(n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
void insertsort(int n)
{
    for (int i = 2; i <= n; i++) //将第一个数作为基准，进行n-1趟排序
    {
        int temp = a[i], j = i;
        while (j > 0 && temp < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}