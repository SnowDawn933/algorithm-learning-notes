//归并排序的实现方法：递归实现  在合并子列(merge函数)时使用了 two pointer 的思想
#include <cstdio>
void merge(int a[], int l1, int r1, int l2, int r2);
void mergesort(int a[], int left, int right);
int main(void)
{
    int a[110];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
void mergesort(int a[], int left, int right)
{
    if (left < right) //只要left<right
    {
        int mid = (left + right) / 2; //取中点
        mergesort(a, left, mid);      //递归，将左右区间分别进行归并排序
        mergesort(a, mid + 1, right);
        merge(a, left, mid, mid + 1, right); //将左右区间合并
    }
}
void merge(int a[], int l1, int r1, int l2, int r2) // 使用了 two pointer 的思想，将两个有序的数列合并到一个数列中
{
    int i = l1, j = l2;        //i指向左边序列的开始，j指向右边序列的开始
    int temp[110], index = 0;  //将两个序列的数先暂时存入temp中
    while (i <= r1 && j <= r2) //将两个数列中的每一个元素进行比较，比较小的就放入temp，对应序列向后指一位
    {
        if (a[i] < a[j])
        {
            temp[index++] = a[i++];
        }
        else
        {
            temp[index++] = a[j++];
        }
    }
    while (i <= r1) //最后将剩余的存入temp
        temp[index++] = a[i++];
    while (j <= r2)
        temp[index++] = a[j++];
    for (int i = 0; i < index; i++) //将合并后的序列赋值回数组a
    {
        a[l1 + i] = temp[i];
    }
}