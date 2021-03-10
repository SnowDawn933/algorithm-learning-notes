#include <stdio.h>
#include <algorithm>
using namespace std;
int weight[10010];
void mergesort(int a[], int n);
void merge(int a[], int l1, int r1, int l2, int r2);
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &weight[i]);
    }
    long long sum = 0;
    while (n > 1)
    {
        mergesort(weight, n);
        weight[1] += weight[2];
        sum += weight[1];
        for (int i = 2; i <= n; i++)
        {
            weight[i] = weight[i + 1];
        }
        n--;
    }
    printf("%lld", sum);
    return 0;
}
void mergesort(int a[], int n)
{
    for (int step = 2; step / 2 <= n; step *= 2)
    {
        for (int i = 1; i <= n; i += step)
        {
            int mid = i + step / 2 - 1;
            if (mid + 1 <= n)
            {
                merge(a, i, mid, mid + 1, min(n, i + step - 1));
            }
        }
    }
}
void merge(int a[], int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2;
    int temp[10010], index = 0;
    while (i <= r1 && j <= r2)
    {
        if (a[i] <= a[j])
            temp[index++] = a[i++];
        else
            temp[index++] = a[j++];
    }
    while (i <= r1)
        temp[index++] = a[i++];
    while (j <= r2)
        temp[index++] = a[j++];
    for (i = 0; i < index; i++)
        a[l1 + i] = temp[i];
}
