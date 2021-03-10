#include<stdio.h>
int main(void)
{
	char ch;
	int a;
	scanf("%c",&ch);
	a=ch-'A'+1;//求输入的字母与A差多少位 
	for (int i=0;i<a;i++)//一共那么多行字母 
	{
		char temp='A'-1;//方便使用++i； 
		for(int j=0;j<a-i-1;j++)
			printf(" ");
		for(int k=0;k<=i;k++)
		{ 
			printf("%c",++temp);
		}
		for(int k=0;k<i;k++)
		{
			printf("%c",--temp);//先减去一再打印 
		}
		printf("\n"); 
	}
	return 0;
}
