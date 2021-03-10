#include<stdio.h>
struct Student
{
    int num, a, b;
};
int main(void)
{
    double ans;
    int n,point;
    int num, a, b;
    struct Student student[1010];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &student[i].num);
        scanf("%d", &student[i].a);
        scanf("%d", &student[i].b);
        ans = student[i].a * 0.7 + student[i].b * 0.3;
        point = student[i].a + student[i].b;
        if(ans>=80&&point>140)
        {
            printf("Excellent\n");
        }
        else
        {
            printf("Not excellent\n");
        }
    }
    return 0;
}