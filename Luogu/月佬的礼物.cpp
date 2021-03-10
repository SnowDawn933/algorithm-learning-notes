#include <iostream>
#include <Windows.h>
#include <cstdio>

using namespace std;

int Min,sec;



int main()
{
	cout<<"请输入计时多少秒:";
	cin>>sec;
	Min=sec/60;
	sec=sec%60;
	while(sec>=0&&Min>=0)
	{
		while(sec>=0)
		{
			system("cls");
			printf("%d:%02d",Min,sec);
			--sec;
			Sleep(1000);
		}
		Min--;
		sec=59;
	}
}


