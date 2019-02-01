#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
//	freopen("input.txt", "r", stdin);
	int i, n, c, a[200004], interval, count;
	int ll, lm, lr, prev;
	interval = 0;
	scanf("%d %d", &n, &c);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	ll = 1;
	lr = 0x7fffffff;
	while (ll <= lr) {
		count = 1;
		lm = (ll + lr) / 2;
		prev = a[0];
		for (i = 1; i < n; i++) {
			if (a[i] - prev >= lm) {
				prev = a[i];
				count++;
			}
		}
		if (count >= c) {
			ll = lm + 1;
			interval = interval < lm ? lm : interval;
		}
		else {
			lr = lm - 1;
		}
	}
	printf("%d", interval);
}
