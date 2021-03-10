#include<stdio.h>
int main()
{
	int n,k,a,b,e,f,sum=0,g=0,m,h;
	scanf("%d\n",&n);//开始有n根烟 
	scanf("%d",&k);//没k个可再换一根 
	a=n/k;//吸完n根还能拼出完整的几个 
	m=a;
	b=n%k;//拼完一轮还剩几个烟蒂 
	h=a+b;
	while(h>=k)
		{
			e=h/k;//总烟蒂数再拼 
			f=h%k;//拼完剩几个 
			sum+=e;//拼出来的总数 
			h=e+f;
		}
	g=sum+m+n;
	printf("%d",g);
	return 0;
} 
