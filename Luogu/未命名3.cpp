#include <stdio.h>
#pragma warning(disable:4996);
//ºöÂÔvsµÄscanf_sµÄ¾¯¸æ
int main()
{
	int x, day;
	scanf("%d%d", &x, &day);
	unsigned long long miles;
	miles = 0;
	for (x; x <= day; x++)
	{
		if (x%6!= 0 || x % 7 != 0)
		{
			miles += 250;
		}
	}
	printf("%lld", miles);
	return 0;
}
