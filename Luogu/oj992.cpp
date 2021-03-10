#include <stdio.h>
#include <string.h>
int main(void)
{
	int len;
	char s[110];
	scanf("%s", s);
	len = strlen(s);
	printf("%d\n", len);
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", s[i] - 'a' + 1);
	}
	return 0;
}
