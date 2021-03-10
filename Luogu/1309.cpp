#include <stdio.h>
#include <algorithm>
using namespace std;
struct player //存储每一个选手的信息
{
    int score; //分数能力和序号
    int ability;
    int id;
} players[210100], win[105050], lose[105050]; //数组一定要开大一点
bool cmp(player a, player b);                 //比较函数
void fight();                                 //比赛函数
int n, r, q;
int main(void)
{
    scanf("%d%d%d", &n, &r, &q);
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%d", &players[i].score);
        players[i].id = i;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%d", &players[i].ability);
    }
    sort(players + 1, players + 1 + 2 * n, cmp); //一开始时是无序的
    for (int i = 1; i <= r; i++)                 //进行r轮比赛
        fight();
    printf("%d", players[q].id);
    return 0;
}
bool cmp(player a, player b) //题目中的比较规则
{
    if (a.score != b.score)
        return a.score > b.score;
    else
    {
        return a.id < b.id;
    }
}
void fight()
{
    int a1 = 0, b1 = 0; //两个指针
    for (int i = 1; i < 2 * n; i += 2)
    { //胜者一组败者一组，最后进行归并排序
        if (players[i].ability > players[i + 1].ability)
        {
            players[i].score++;
            win[++a1] = players[i];
            lose[++b1] = players[i + 1];
        }
        else
        {
            players[i + 1].score++;
            win[++a1] = players[i + 1];
            lose[++b1] = players[i];
        }
    }
    a1 = 1, b1 = 1;
    int cnt = 1;
    while (a1 <= n && b1 <= n)
    {
        if (cmp(win[a1], lose[b1]))
            players[cnt++] = win[a1++];
        else
            players[cnt++] = lose[b1++];
    }
    while (a1 <= n)
        players[cnt++] = win[a1++];
    while (b1 <= n)
        players[cnt++] = lose[b1++];
}