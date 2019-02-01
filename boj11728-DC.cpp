#include<stdio.h>
int a[1000000], b[1000000];
int main()
{
///	freopen("input.txt", "r", stdin);
	int n, m, as, bs, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	as = bs = i = 0;
	while (i < n + m) {
		if (as != n && bs != m) {
			if (a[as] < b[bs]) printf("%d ", a[as++]);
			else printf("%d ", b[bs++]);
		}
		else if (as == n) {
			printf("%d ", b[bs++]);
		}
		else if (bs == m) {
			printf("%d ", a[as++]);
		}
		i++;
	}
}
