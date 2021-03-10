#include<stdio.h>
int main()
{
	int a,b,c,d=1,e,f,min,m,n;
	scanf("%d",&c);
	scanf("%d %d",&m,&n);
	if(c%m==0)
		e=c/m;
	else
		e=c/m+1;
	min=e*n;	
	while (d<3)
		{
			scanf("%d %d",&a,&b);
			if(c%a==0)
				e=c/a;
			else
				e=c/a+1;
			f=e*b;
			if(f<=min)
				min=f;
			d++;
		}
	printf("%d",min);
	return 0;
		
}

