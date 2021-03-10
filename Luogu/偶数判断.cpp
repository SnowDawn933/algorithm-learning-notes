#include<stdio.h>
#include<math.h>
int main(void)
{

		int x;
		double y;
		scanf("%d", &x);
		if (x > 0)
		{
			y = exp(-x);
		}
		else if (x < 0)
		{
			y = -exp(x);
		}
		else
		{
			y=1;
		}
		printf("y=%f\n", y);
		return 0;
}