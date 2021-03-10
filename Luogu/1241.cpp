#include <cstdio>
#include <cstring>
using namespace std;

int len, tot;
char t[1005];   //字符串读入括号序列
bool mem[1005]; //标记数组

int main(void)
{
    scanf("%s", t + 1);
    len = strlen(t + 1);

    for (int i = 1; i <= len; i++) //遍历字符串
    {
        if (t[i] == ']')
        {
            for (int j = i - 1; j >= 1; j--) //查找是否有满足条件的括号
            {
                if (t[j] == '(' && !mem[j])
                    break;
                if (t[j] == '[' && !mem[j])
                {
                    mem[i] = 1;
                    mem[j] = 1;
                    break;
                }
            }
        }
        else if (t[i] == ')')
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (t[j] == '[' && !mem[j])
                    break;
                if (t[j] == '(' && !mem[j])
                {
                    mem[i] = 1;
                    mem[j] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= len; i++)
    {
        if (mem[i])
            printf("%c", t[i]); //输出
        else
        {
            if (t[i] == '(')
                printf("%c)", t[i]); //补全括号并输出
            else if (t[i] == ')')
                printf("(%c", t[i]);
            else if (t[i] == '[')
                printf("%c]", t[i]);
            else
                printf("[%c", t[i]);
        }
    }

    return 0;
}