#include<stdio.h>
int isprime[2001000];
int main(void)
{
    int n,t;
    double a;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%lf%d", &a, &t);
        for (int j = 1; j <= t;j++)
        {
            if (isprime[int(j*a)]==0)
            {
                isprime[int(j * a)] = 1;
            }
            else
            {
                isprime[int(j * a)] = 0;
            }     
        }
            
    }
    for (int i = 1;;i++)
    {
        if(isprime[i]==1)
        {
        	printf("%d",i);
			break; 
		}
    }
    return 0;
}
