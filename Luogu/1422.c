#include<stdio.h>
#define PRICE_1 0.4463
#define PRICE_2 0.4663
#define PRICE_3 0.5663
int main(void)

{
	int a;
	double b,c,d;
	c=150*PRICE_1;
	d=250*PRICE_2;
	scanf("%d",&a);
	if(a<=150)
		b=a*PRICE_1;
	if(a>150&&a<=400)
		b=c+PRICE_2*(a-150);
	if(a>400)
		b=c+d+PRICE_3*(a-400);
	printf("%.1f",b);
	return 0;
		
	
	
	
 } 
