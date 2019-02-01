#include<stdio.h>
int a[1000004]; //너무 커서 
int main()
{
	freopen("input.txt", "r", stdin);
	long long i, n, h, cut_length, target_length;
	long long ll, lm, lr; //이분탐색을 위한
	h = 0;
	scanf("%lld %lld", &n, &target_length);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	ll = 0;
	lr = 0x7fffffffffffffff;
	while (ll <= lr) {
		cut_length = 0;
		lm = (ll + lr) / 2;
		for (i = 0; i < n; i++) {
			if (a[i] - lm > 0) {
				cut_length += a[i] - lm;
			}
		}
		if (cut_length >= target_length) {
			ll = lm + 1;
			h = lm < h ? h : lm;
		}
		else {
			lr = lm - 1;
		}
	}
	printf("%lld", h);
}
