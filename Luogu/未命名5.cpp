#include<stdio.h>
#include<string.h>
int main(void)
{
	char first_name[40],last_name[40];
	int first_length,last_length;
	printf("Please input your first_name:");
	scanf("%s",first_name);
	printf("Please input your last_name:");
	scanf("%s",last_name);
	first_length=strlen(first_name);
	last_length=strlen(last_name);
	printf("%s %s\n",first_name,last_name);
	printf("%*d %*d\n",first_length,first_length,last_length,last_length);
	printf("%s %s\n",first_name,last_name);
	printf("%-*d %-*d\n",first_length,first_length,last_length,last_length);
	return 0;
}
