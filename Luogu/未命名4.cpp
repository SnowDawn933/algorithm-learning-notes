#include<stdio.h>
int main(void)
{
	float speed,big,time;
	scanf("%f %f8",&speed,&big);
	time=big/speed;
	printf("At %.2f megabit per second, a file of %.2f megabytes downloads in %.2f seconds.",speed,big,time);
	return 0;
}
