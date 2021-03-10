#include<stdio.h>
int main(void)
{
	int n,i,j,s;//n总只数  s不如自己好看  i  j循环变量 
	scanf("%d",&n);
	int a[105];
	for(i=0;i<n;i++)	//每一只小于鱼 
	{
		s=0;
		scanf("%d",&a[i]);//将每只小鱼的可爱读入数组 
		for(j=i;j>=0;j--)//从当前开始往前面比较 
		{
			if(a[i]>a[j])//找到一只就加一 
				s++;
		}
		printf("%d ",s);输出 
	}
	return 0;
}
