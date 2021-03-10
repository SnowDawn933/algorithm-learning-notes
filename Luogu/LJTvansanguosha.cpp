#include <stdio.h>

int main(void)
{
    int win = 0, lose = 0, wingame = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == 'W')
        {
            win++;
        }
        if (c == 'L')
        {
            lose++;
        }
        if (win == 3)
        {
            win = 0;
            lose = 0;
            wingame++;
        }
        if(lose==3)
        {
            win = 0;
            lose = 0;
        }
    }
    printf("%d", wingame);
    return 0;
}