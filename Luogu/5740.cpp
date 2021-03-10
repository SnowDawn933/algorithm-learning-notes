#include<stdio.h>
#include<string.h>
struct Student
{
    char name[10];
    int ch;
    int math;
    int eng;
};
int main (void)
{
    int cnt,sum=0,max=0,num=0;
    struct Student student[1010];
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        scanf("%s", student[i].name);
        scanf("%d%d%d", &student[i].ch, &student[i].math, &student[i]. eng);
        sum = student[i].ch + student[i].math + student[i].eng;
        if(sum>max)
        {
            max = sum;
            num = i;
        }
    }
    printf("%s ", student[num].name);
    printf("%d %d %d", student[num].ch, student[num].math, student[num].eng);
    return 0;
}
