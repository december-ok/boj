#include<stdio.h>
#include<algorithm>
using namespace std;
int a[5000003];
int main()
{
//	freopen("input.txt", "r", stdin);
	int i, m, n, t;
	int ll, lm, lr;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		ll = 0;
		lr = n;
		int flag = 1;
		scanf("%d", &t);
		while (ll <= lr) {
			lm = (ll + lr) / 2;
			if (a[lm] == t) {
				printf("1 ");
				flag = 0;
				break;
			}
			else if (a[lm] > t) {
				lr = lm - 1;
			}
			else {
				ll = lm + 1;
			}
		}
		if (flag) {
			printf("0 ");
		}
	}
}
