#include<stdio.h>
int main(void)
{
	int a,b=1,i,j;
	scanf("%d",&a);
	for(i=a;i>=1;i--)
	{
			j=0;
				while(j<i)
				{ 
					if(b<10)
					{
						printf("0%d",b);
					}	
					else
						printf("%d",b);
					j++;
					b++;
				}
				printf("\n");
	}
	return 0;
}
				
					
				
		
	
  
