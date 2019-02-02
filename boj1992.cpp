#include<stdio.h>
int ar[70][70];
void check(int a, int b, int length, int con) {
	int i, j, flag;
	flag = 0;
	for (i = a; i < a + length; i++) {
		for (j = b; j < b + length; j++) {
			if (con != ar[i][j]) {
				flag = 1;
				break;
			}
		}
		if (flag)break;
	}
	if (flag) {
		printf("(");
		for (i = a; i < a + length; i += length / 2) {
			for (j = b; j < b + length; j += length / 2) {
				check(i, j, length / 2, ar[i][j]);
			}
		}
		printf(")");
	}
	else {
		printf("%d", ar[a][b]);
	}
}
int main() {
	/////freopen("input.txt", "r", stdin);
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%1d", &ar[i][j]);
		}
	}
	check(0, 0, n, ar[0][0]);
}
