

#include <stdio.h>
int isprime(int num)
{

	for (int i = 2; (i * i) <= num; i++)
	{
		if (num % i == 0 || num == 1)
			return 0;
	}
	return 1;
}
int main(void)
{
	int a, b, c = 0, num;
	scanf("%d%d", &a, &b);
	for (int a1 = 5; a1 <= 9; a1++) //һλ������
	{
		int c = 0;
		for (int i = 2; i <= a1 - 1; i++) //�ж�����
		{
			if (a1 % i == 0)
			{
				c = 1;
				break;
			}
		}
		if (a1 <= b && a1 >= a && c == 0) //�ж��Ƿ��ڷ�Χ��
			printf("%d\n", a1);
	}
	for (int a2 = 1; a2 <= 9; a2 += 2) //��λ������
	{
		num = 10 * a2 + a2;
		if (num <= b && num >= a && isprime(num) == 1)
			printf("%d\n", num);
	}
	for (int d1 = 1; d1 <= 9; d1 += 2) //��λ������
	{
		for (int d2 = 0; d2 <= 9; d2++)

		{
			num = 100 * d1 + 10 * d2 + d1;

			if (num <= b && num >= a && isprime(num) == 1)
				printf("%d\n", num);
		}
	}

	for (int d1 = 1; d1 <= 9; d1 += 2) //��λ������
	{
		for (int d2 = 0; d2 <= 9; d2++)
		{
			for (int d3 = 0; d3 <= 9; d3++)
			{
				num = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
				if (num <= b && num >= a && isprime(num) == 1)
					printf("%d\n", num);
			}
		}
	}

	for (int d1 = 1; d1 <= 9; d1 += 2) //��λ������
	{
		for (int d2 = 0; d2 <= 9; d2++)
		{
			for (int d3 = 0; d3 <= 9; d3++)
			{
				for (int d4 = 0; d4 <= 9; d4++)
				{
					num = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
					if (num <= b && num >= a && isprime(num) == 1)
						printf("%d\n", num);
				}
			}
		}
	}

	return 0;
}
