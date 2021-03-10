#include<stdio.h>
#include<algorithm>
using namespace std;
struct per
{
    int data;
    int no;
} per[1000010];
bool cmp(struct per a, struct per b)
{
    return a.data < b.data;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &per[i].data);
        per[i].no = i+1;
    }
    sort(per, per + n, cmp);
    double sum[n + 10],sum1=0;
    for (int i = 0; i < n;i++)
    {
        printf("%d ", per[i].no);
        sum[i] = sum1;
        sum1 += per[i].data;        
    }
    printf("\n");
    sum1 = 0;
    for (int i = 0; i < n;i++)
    {
        sum1 += sum[i];
    }
    printf("%.2lf", sum1 / n);
    return 0;
}