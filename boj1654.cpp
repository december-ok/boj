#include<stdio.h>
#include<string.h>
int main()
{
	//freopen("input.txt", "r", stdin);
	long long i, temp, t, n, m, a[10003], num, max;
	long long ll, lr, lm;
	t = 0;
	max = 0;
	scanf("%lld %lld", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	ll = 0;
	lr = 0x7fffffffffffffff;
	do {
		lm = (ll + lr) / 2;
		temp = 0; 
		for (i = 0; i < n; i++) {
			temp += a[i] / lm;
		}
		if (temp >= m) {
			ll = lm + 1;
			max = lm > max ? lm : max;
		}
		else {
			lr = lm - 1;
		}
	} while (ll <= lr);
	printf("%lld", max);
}
