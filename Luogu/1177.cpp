#include <cstdio>
int n, a[1000050];
void qsort(int l, int r);
int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(1, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void qsort(int l, int r)
{
    int i = l, j = r;
    int mid = a[(l + r) / 2];
    do
    {
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j)
        qsort(l, j);
    if (r > i)
        qsort(i, r);
}