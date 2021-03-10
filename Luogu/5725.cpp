#include<stdio.h>
int main(void)
{
	int a,num=1,j;
	scanf("%d",&a);
	for (int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(num<10)
			  	printf("0%d",num);
			else
				printf("%d",num);
			num++;
		}
		printf("\n");
	}
	printf("\n");
	num=1;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(j<=(a-i))
			printf("  ");
			else
			{ 
				if(num<10)
			  		printf("0%d",num);
				else
					printf("%d",num);
					num++;	
			}
		}
		printf("\n");
	}
	return 0;  
}
