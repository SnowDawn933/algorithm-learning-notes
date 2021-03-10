#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define High 15
#define Width 20

struct node1
{
    int x, y;
    int vx, vy;
} ball;

struct node2
{
    int x, y;
    int length;
    int l, r;
    int v;
} board;

int canvas[High][Width];

void HideCursor(void)
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void restart(void)
{
    ball.x = 0;
    ball.y = Width / 2;
    ball.vx = 1;
    ball.vy = 1;
    canvas[ball.x][ball.y] = 1;

    board.length = 5;
    board.x = High - 1;
    board.y = Width / 2;
    board.l = board.y - board.length;
    board.r = board.y + board.length;
    board.v = 1;

    for (int k = board.l; k <= board.r; k++)
    {
        canvas[board.x][k] = 2;
    }
}

void show(void)
{
    gotoxy(0, 0);
    for (int i = 0; i < High; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            if (canvas[i][j] == 0)
            {
                printf(" ");
            }
            else if (canvas[i][j] == 1)
            {
                printf("O");
            }
            else if (canvas[i][j] == 2)
            {
                printf("*");
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < Width; j++)
    {
        printf("_");
    }
    printf("\n");
}

void behindtheshow(void)
{
    if (ball.x == High - 2)
    {
        if ((ball.y >= board.l) && (ball.y <= board.r))
        {
            printf("\a");
        }
        else
        {
            printf("GAME OVER!!!");
            system("pause");
            exit(0);
        }
    }

    canvas[ball.x][ball.y] = 0;

    ball.x = ball.x + ball.vx;
    ball.y = ball.y + ball.vy;

    if (ball.x == 0 || ball.x == High - 2)
    {
        ball.vx = -ball.vx;
    }
    if (ball.y == 0 || ball.y == Width - 1)
    {
        ball.vy = -ball.vy;
    }

    canvas[ball.x][ball.y] = 1;

    Sleep(50);
}

void playerint(void)
{
    char input;
    if (kbhit())
    {
        input = getch();
        if (input == 'j' && board.l > 0)
        {
            canvas[board.x][board.r] = 0;
            board.y -= board.v;
            board.r = board.y + board.length;
            board.l = board.y - board.length;
            canvas[board.x][board.l] = 2;
        }
        if (input == 'l' && board.r < Width - 1)
        {
            canvas[board.x][board.l] = 0;
            board.y += board.v;
            board.r = board.y + board.length;
            board.l = board.y - board.length;
            canvas[board.x][board.r] = 2;
        }
    }
}

int main()
{
    restart();
    while (1)
    {
        show();
        behindtheshow();
        playerint();
    }
    return 0;
}
