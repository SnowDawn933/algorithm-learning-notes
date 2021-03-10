#include <cstdio>
#include <cstring>
char ans[90][90];
int main(void)
{
    char str[90];
    gets(str);
    int len = strlen(str), r = 0, l = 0;
    
    for (int i = 0; i < len; i++)
    {
        if(str[i]!=' ')
            ans[r][l++] = str[i];//不是空格的话就把它存到相应的地方。
        else
        {
            ans[r][l] = '\0';//是的话就结束这个字符
            r++;
            l = 0;//进行下一个单词的载入
        }
    }
    for (int i = r; i >= 0;i--)
    {
        printf("%s", ans[i]);
        if(i>0)
            printf(" ");
    }
    return 0;
}