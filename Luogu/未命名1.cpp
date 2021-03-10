#include <stdio.h>

int main(void)
{
	int a, b;
	float result ;
	char fu;
	scanf("%d%c%d", &a,&fu, &b);
	switch (fu)
	{
	case '+':
		result = a + b;
		break;

	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a *1.0/ b;
		break;
	}
	printf("%f", result);
	return 0;
}