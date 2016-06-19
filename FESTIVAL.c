#include <stdio.h>

double cost[1001];
int n, l;

double MinSum(int cnt)
{
	int i, j = 0;
	double sum = 0.0;
	double min = 1000000000.0;
	int temp = cnt;

	while (cnt <= n - l)
	{
		sum = 0.0;
		for (i = j; i < l + cnt; i++)
		{
			sum += cost[i];
		}
		j++;
		cnt++;
		if (min > sum)
			min = sum;

	}
	return min / (l + temp);
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k;
	int i;
	double aver;
	double min = 1000000000.0;
	int c;
	double minarr[1001];
	scanf("%d", &c);
	int j;


	for (k = 0; k < c; k++)
	{
		scanf("%d %d", &n, &l);
		for (i = 0; i < n; i++)
			scanf("%lf", &cost[i]);

		for (j = 0; j <= n - l; j++)
		{
			aver = MinSum(j);
			if (min > aver)
				min = aver;
		}

		minarr[k] = min;

		aver = 0.0;
		min = 1000000000.0;
		
		for (i = 0; i < 1001; i++)
			cost[k] = 0.0;
	}

	for (k = 0; k < c; k++)
	{
		printf("%.12f", minarr[k]);

		if (k < c - 1)
			puts("");
	}

	return 0;
}