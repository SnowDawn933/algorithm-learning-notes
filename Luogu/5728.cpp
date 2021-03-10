#include<stdio.h>
#include<math.h> 
int main(void)
{
	int num,cnt=0,sum,x,y,z;
	scanf("%d",&num);
	int a[num+10],b[num+10],c[num+10];
	scanf("%d%d%d",&a[1],&b[1],&c[1]);
	for(int i=2;i<=num;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		for(int j=1;j<i;j++)
		{
			sum=abs(a[i]+b[i]+c[i]-a[j]-b[j]-c[j]);
			x=abs(a[i]-a[j]);
			y=abs(b[i]-b[j]);
			z=abs(c[i]-c[j]);
			if(x<=5&&y<=5&&z<=5&&sum<=10)
			{		
				cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
 } 
