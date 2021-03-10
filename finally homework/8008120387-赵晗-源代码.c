#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define High 15
#define Width 20

//定义结构体：小球的参数
struct node1
{
    int x, y;
    int vx, vy;
} ball;

//定义结构体：挡板的参数
struct node2
{
    int x, y;
    int length;
    int l, r;
    int v;
} board;

//定义画布
int canvas[High][Width];

//定义总分
int totalscore;

//定义小球的速度
int speed = 50;

//定义文件的句柄，读取地图文件
FILE *fp1 = fopen("map01.txt", "r");
FILE *fp2 = fopen("map02.txt", "r");
FILE *fp3 = fopen("map03.txt", "r");
FILE *fp4 = fopen("map04.txt", "r");
FILE *fp5 = fopen("map05.txt", "r");
FILE *fp6 = fopen("map06.txt", "r");
FILE *fp7 = fopen("map07.txt", "r");
FILE *fp8 = fopen("map08.txt", "r");
FILE *fp9 = fopen("map09.txt", "r");
FILE *fpa = fopen("map0a.txt", "r");
FILE *fpb = fopen("map0b.txt", "r");
FILE *fpc = fopen("map0c.txt", "r");

//隐藏光标的函数，防止其一闪一闪的影响游戏体验
void HideCursor(void)
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//定义函数：将光标指向原点的位置
void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

//菜单函数声明，放在最前面是为了后面的函数中都可以调用它
void list();

//函数定义：重置游戏函数
void restart(FILE *fp)
{
    memset(canvas, 0, sizeof(canvas)); //将画布的所有元素都重置为零
    ball.x = High - 2;                 //初始化小球的参数
    ball.y = Width / 2;
    ball.vx = 1;
    ball.vy = 1;
    canvas[ball.x][ball.y] = 5; //小球的位置用5标记

    board.length = 5; //初始化挡板的参数
    board.x = High - 1;
    board.y = Width / 2;
    board.l = board.y - board.length;
    board.r = board.y + board.length;
    board.v = 1;

    for (int k = board.l; k <= board.r; k++) //将挡板用4标记
    {
        canvas[board.x][k] = 4;
    }

    //读取文件的操作
    if (fp == NULL)
    {
        printf("can not generate the game map , please check the game files!");
        exit(0);
    }

    //将地图文件的数字元素读入画布数组中以生成地图
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < Width - 1; j++)
        {
            fscanf(fp, "%d", &canvas[i][j]);
        }
    }
    fclose(fp);

    //重置总分
    totalscore = 0;
}

//定时显示函数
void show(void)
{
    HideCursor(); //首先解决光标的问题
    gotoxy(0, 0);
    int flag = 0; //判断是否消除完结束游戏的标志

    //依次将相应的元素输出出来
    for (int i = 0; i < High; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            if (canvas[i][j] == 0)
            {
                printf(" ");
            }
            else if (canvas[i][j] == 5)
            {
                printf("O");
            }
            else if (canvas[i][j] == 4)
            {
                printf("*");
            }
            else if (canvas[i][j] == 1)
            {
                printf("#");
            }
            else if (canvas[i][j] == 2) //不同的元素输出的颜色不一样，所以改变字体的颜色
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                printf("#");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
            }
            else if (canvas[i][j] == 3)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                printf("#");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
            }
            else if (canvas[i][j] == -1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                printf("T");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
            }
            else if (canvas[i][j] == -2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                printf("T");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
            }
            else if (canvas[i][j] == -3)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_INTENSITY |
                                                                             FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                printf("T");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
                                                                             FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < Width; j++) //输出地图的边界
    {
        printf("_");
    }
    printf("\n");
    printf("       得分：%d\n", totalscore); //实时输出当前的得分

    //判断区域内还是否有元素
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            if (canvas[i][j] != 0)
                flag++;
        }
    }

    //如果没有元素那么就说明玩家消除全部的砖块，游戏结束，胜利
    if (flag == 0)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n");
        printf("     恭喜你！通过了本关！\n");
        printf("     按空格键返回主菜单");
        char ch;
        ch = getch();
        if (ch == ' ')
            list();
    }
}

//定义函数，画布数组的值随着游戏的进行发生的变化，show（）函数依次来更新画面
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
            printf("          GAME OVER!!!\n"); //游戏失败的条件
            printf("     按空格键返回主菜单");
            char ch;
            ch = getch();
            if (ch == ' ')
                list();
        }
    }

    canvas[ball.x][ball.y] = 0; //小球的运动导致的参数的值的变化
    ball.x = ball.x - ball.vx;
    ball.y = ball.y + ball.vy;
    canvas[ball.x][ball.y] = 5;

    //小球碰到墙壁的变化
    if (ball.x == 0 || ball.x == High - 2)
    {
        ball.vx = -ball.vx;
    }
    if (ball.y == 0 || ball.y == Width - 1)
    {
        ball.vy = -ball.vy;
    }

    //吃到小球加速道具之后的变化
    if (canvas[ball.x - ball.vx][ball.y] == -1)
    {
        speed = 25;
        canvas[ball.x - ball.vx][ball.y]++;
        ball.vx = -ball.vx;
        printf("\a");
        totalscore++;
    }

    //吃到炸弹道具之后的变化，分数分别加上相应的值，该画布出变为代表这空白的0
    if (canvas[ball.x - ball.vx][ball.y] == -2)
    {
        canvas[ball.x - ball.vx][ball.y] += 2;

        if (ball.y + ball.vy <= Width - 2 && ball.y + ball.vy > 0)
        {
            totalscore += canvas[ball.x - ball.vx][ball.y + ball.vy];
            canvas[ball.x - ball.vx][ball.y + ball.vy] = 0;
        }

        if (ball.y - ball.vy <= Width - 2 && ball.y - ball.vy > 0)
        {
            totalscore += canvas[ball.x - ball.vx][ball.y - ball.vy];
            canvas[ball.x - ball.vx][ball.y - ball.vy] = 0;
        }

        if (ball.x - ball.vx - 1 > 0)
        {
            totalscore += canvas[ball.x - ball.vx - 1][ball.y];
            canvas[ball.x - ball.vx - 1][ball.y] = 0;
        }

        if (ball.x - ball.vx - 1 > 0 && ball.y - ball.vy <= Width - 2 && ball.y - ball.vy > 0)
        {
            totalscore += canvas[ball.x - ball.vx - 1][ball.y - ball.vy];
            canvas[ball.x - ball.vx - 1][ball.y - ball.vy] = 0;
        }

        if (ball.x - ball.vx - 1 > 0 && ball.y + ball.vy <= Width - 2 && ball.y + ball.vy > 0)
        {
            totalscore += canvas[ball.x - ball.vx - 1][ball.y + ball.vy];
            canvas[ball.x - ball.vx - 1][ball.y + ball.vy] = 0;
        }
        ball.vx = -ball.vx;
        printf("\a");
        totalscore++;
    }

    //吃到挡板变短的道具之后的变化，缩短挡板的半径参数
    if (canvas[ball.x - ball.vx][ball.y] == -3)
    {
        board.length = 3;
        canvas[ball.x - ball.vx][ball.y] += 3;
        ball.vx = -ball.vx;
        printf("\a");
        totalscore++;
    }

    //碰到砖块后的参数变化和反弹机制的实现
    if (canvas[ball.x - ball.vx][ball.y] == 1 || canvas[ball.x - ball.vx][ball.y] == 2 || canvas[ball.x - ball.vx][ball.y] == 3)
    {
        canvas[ball.x - ball.vx][ball.y]--;
        if (canvas[ball.x - ball.vx][ball.y] == 0)
        {
            if (ball.y + ball.vy <= Width - 2 && canvas[ball.x - ball.vx][ball.y + ball.vy] > 0 && ball.y + ball.vy > 0)
            {
                canvas[ball.x - ball.vx][ball.y + ball.vy]--;
                totalscore++;
            }
            if (ball.y - ball.vy <= Width - 2 && canvas[ball.x - ball.vx][ball.y - ball.vy] > 0 && ball.y - ball.vy > 0)
            {
                canvas[ball.x - ball.vx][ball.y - ball.vy]--;
                totalscore++;
            }
        }
        ball.vx = -ball.vx;
        printf("\a");
        totalscore++;
    }

    //刷新率，可以以此来改变小球的运动速度
    Sleep(speed);
}

//游戏玩家操作相关的函数
void playerint(void)
{
    char input;
    if (kbhit()) //判断是否有键盘的输入
    {
        input = getch(); //控制台输入函数，不会将输入的值显示荧光屏幕上
        //实现挡板的移动，即改变挡板的中心，依次向两边的半径来输出代表平板的*
        if (input == 'j' && board.l > 0)
        {
            canvas[board.x][board.r] = 0;
            board.y -= board.v;
            board.r = board.y + board.length;
            board.l = board.y - board.length;
            canvas[board.x][board.l] = 4;
        }
        if (input == 'l' && board.r < Width - 1)
        {
            canvas[board.x][board.l] = 0;
            board.y += board.v;
            board.r = board.y + board.length;
            board.l = board.y - board.length;
            canvas[board.x][board.r] = 4;
        }
    }
}

//帮助菜单函数
void helplist(void)
{
    system("cls");
    printf("************************************************\n");
    printf("*             打砖块游戏帮助                   *\n");
    printf("*                                              *\n");
    printf("* 1.如何控制平板的移动                         *\n");
    printf("*     将输入法转换为美式键盘，使用‘j’左移      *\n");
    printf("*     平板，‘l’右移平板。                      *\n");
    printf("* 2.移动平板，接住小球，保证小球不从下边界     *\n");
    printf("*   飞出界面外                                 *\n");
    printf("* 3.每击中一次砖块，累加一分                   *\n");
    printf("* 4.砖块说明：                                 *\n");
    printf("*     黑色：生命值1                            *\n");
    printf("*     蓝色：生命值2                            *\n");
    printf("*     红色：生命值3                            *\n");
    printf("* 5.道具说明（T）：                            *\n");
    printf("*     绿色的T：小球的运动速度变为两倍          *\n");
    printf("*     黄色的T：小球获得一次爆炸，可直接消灭    *\n");
    printf("*              周围3*3范围内所有砖块           *\n");
    printf("*     青色的T：DEBUFF，平板的长度缩短          *\n");
    printf("* 6.小球的打击效果：                           *\n");
    printf("*   孤立无援：                                 *\n");
    printf("*      若所击中的砖块为孤立的状态（即左右两边  *\n");
    printf("*   已被击毁），则直接贯穿至其后面的砖块。     *\n");
    printf("*   背后打击：                                 *\n");
    printf("*      若小球从背后击中一块砖，那么无论其生命  *\n");
    printf("*   值为多少，则直接击穿。                     *\n");
    printf("*   爆裂：                                     *\n");
    printf("*        若一块砖被正面击毁，则触发爆炸效果    *\n");
    printf("*    使周围的存活砖块生命值-1                  *\n");
    printf("*   连锁爆破：                                 *\n");
    printf("*       被炸毁的砖块也可以触发爆炸效果         *\n");
    printf("************************************************\n");
    printf("             按‘1’返回菜单界面              \n");
    char ch;
    ch = getch();
    if (ch == '1')
        list();
}

//选择关卡函数
void pickmap(void)
{
    printf("*******************************************\n");
    printf("*               请选择关卡                 *\n");
    printf("*                                         *\n");
    printf("*         1      2      3       4         *\n");
    printf("*                                         *\n");
    printf("*         5      6      7       8         *\n");
    printf("*                                         *\n");
    printf("*         9      a      b       c         *\n");
    printf("*                                         *\n");
    printf("*           按相应的按键即可进入           *\n");
    printf("*                                         *\n");
    printf("*******************************************\n");
    char ch;
    ch = getch();
    system("cls");
    switch (ch)
    {
    case '1':
    {
        restart(fp1);
        break;
    }
    case '2':
    {
        restart(fp2);
        break;
    }
    case '3':
    {
        restart(fp3);
        break;
    }
    case '4':
    {
        restart(fp4);
        break;
    }
    case '5':
    {
        restart(fp5);
        break;
    }
    case '6':
    {
        restart(fp6);
        break;
    }
    case '7':
    {
        restart(fp7);
        break;
    }
    case '8':
    {
        restart(fp8);
        break;
    }
    case '9':
    {
        restart(fp9);
        break;
    }
    case 'a':
    {
        restart(fpa);
        break;
    }
    case 'b':
    {
        restart(fpb);
        break;
    }
    case 'c':
    {
        restart(fpc);
        break;
    }
    }
}

//”关于游戏“函数
void aboutthegame(void)
{
    system("cls");
    printf("*******************************************\n");
    printf("*              关于此游戏                 *\n");
    printf("*                                         *\n");
    printf("* 1.游戏名称：打砖块                      *\n");
    printf("* 2.版本信息：1.3.16                      *\n");
    printf("* 3.更新时间：2021.1.06                   *\n");
    printf("* 4.开发者信息：                          *\n");
    printf("*     南昌大学   软件学院  计算机二类     *\n");
    printf("*     2013班      赵晗     Snow_Dawn      *\n");
    printf("*******************************************\n");
    printf("            按‘1’键返回菜单       \n");
    char ch;
    ch = getch();
    if (ch == '1')
        list();
}

//控制着开是游戏的函数
void startgame(void)
{
    system("cls"); //每次开始前都要先将屏幕清理干净
    pickmap();
    while (1) //不断循环重复以打到动态的效果
    {
        show();
        behindtheshow();
        playerint();
    }
}

//游戏菜单函数
void list(void)
{
    system("cls");

    printf("*******************************************\n");
    printf("*                 打砖块                  *\n");
    printf("*                                         *\n");
    printf("*              1.开始游戏                 *\n");
    printf("*                                         *\n");
    printf("*              2.游戏帮助                 *\n");
    printf("*                                         *\n");
    printf("*              3.关于游戏                 *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("*   version:    1.3.16                    *\n");
    printf("*   ©2020   赵晗   All rights reserved    *\n");
    printf("*******************************************\n");
    printf("            请从1-3中选择按键:             \n");

    char ch;
    ch = getch(); //利用swicth函数来完成选择的功能实现

    switch (ch)
    {
    case '1':
    {
        startgame();
        break;
    }
    case '2':
    {
        helplist();
        break;
    }
    case '3':
    {
        aboutthegame();
        break;
    }
    }
}

int main(void) //将所有功能嵌套在一起实现的主函数
{
    system("mode con cols=60 lines=40"); //根据游戏的区域大小设置合适的窗口大小
    system("color F0");                  //设置游戏的背景颜色为白色画布黑色字体
    list();                              //一切嵌套函数的开始
    return 0;
}
