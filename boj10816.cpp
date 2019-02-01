#include<stdio.h>
int record[20000002];
int main()
{
//	freopen("input.txt", "r", stdin);
	int i, m, n, t;
	int ll, lm, lr;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		record[t + 10000000]++;
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &t);
		printf("%d ", record[t + 10000000]);
	}
}
