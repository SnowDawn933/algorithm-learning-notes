#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int l=1, r=1;
	int res=1;
	while(r<n)
	{
		if(res<n)
		{
			r++;
			res+=r;
		}
		else 
			if(res>n)
			{
				res-=l;
				l ++;
			}
		else
		{
			printf("%d %d\n",l,r);
			r++;
			res+=r;
		}
	}
	return 0;
 } 
 

