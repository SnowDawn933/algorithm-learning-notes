#include<stdio.h>
int main(void)
{
	int a,b,c,e,d,f,bigger,smaller;
	scanf("%d %d %d",&a,&b,&c);
	if(a<b)
		{
			e=a;
			a=b;
			b=e;
		}
	if(a<c)
		{
			e=a;
			a=c;
			c=e;
		}
	if(b<c)
		{
			e=b;
			b=c;
			c=e;
		}
	bigger=a*a;
	d=b*b;
	f=c*c;
	smaller=d+f;
	if(b+c<=a)
		printf("Not triangle\n");
	else
		{
			if(bigger>smaller)
				printf("Obtuse triangle\n");
			if(bigger==smaller)
				printf("Right triangle\n");
			if(bigger<smaller)
				printf("Acute triangle\n");
		
			if(c==b||a==b||a==c)
				{
					printf("Isosceles triangle\n");
					if(a==b&&b==c)
						printf("Equilateral triangle\n");
				}
		}
		
	return 0;
			
	
}
