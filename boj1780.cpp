#include<stdio.h>
int ar[3000][3000], record[3];
void dc(int a, int b, int length, int in) {
	int i, j, flag;
	flag = 0;
	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			if (ar[a + i][b + j] != in) {
				flag = 1;
			}
			if (flag) break;
		}
		if (flag) break;
	}
	if (flag) {
		for (i = 0; i < length; i += length / 3) {
			for (j = 0; j < length; j += length / 3) {
				dc(a + i, b + j, length / 3, ar[a + i][b + j]);
			}
		}
	}
	else {
		record[in + 1]++;
	}
}
int main()
{
/////	freopen("input.txt", "r", stdin);
	int j, i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &ar[i][j]);
		}
	}
	dc(0, 0, n, ar[0][0]);
	printf("%d\n%d\n%d", record[0], record[1], record[2]);
}
