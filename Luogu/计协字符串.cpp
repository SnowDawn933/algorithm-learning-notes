#include <stdio.h>
#include <string.h>

struct Stu
{
	int grade;
	char name[30];	
};

int main()
{
	Stu students[30];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++ )
	{
		scanf("%s%d", students[i].name, &students[i].grade);
	}	
	char des[20];
	scanf("%s", des);
	for (int i = 0; i < n; i ++ )
	{
		if (strcmp(students[i].name, des) == 0)
		{
			printf("%d\n", students[i].grade);
			return 0;
		}
	}
}
