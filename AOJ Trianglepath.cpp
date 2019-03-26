#include<stdio.h>
using namespace std;
int A[500][500] = { 0 };
int B[500][500] = { 0 };
int max(int a, int b) { return a > b ? a : b; }
int main() {
	freopen("input.txt", "r", stdin);
	int n, t, i, j, temp = 0; scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		for (i = 0; i < t; i++) {
			for (j = 0; j <= i; j++) {
				scanf("%d", &A[i][j]);
				B[i][j] = 0;
			}
		}
		B[0][0] = A[0][0];
		for (i = 1; i < t; i++) {
			for (j = 0; j <= i; j++) {
				if (j == 0) B[i][j] = B[i - 1][j] + A[i][j];
				if (j == i) B[i][j] = B[i - 1][j - 1] + A[i][j];
				B[i][j] = max(B[i - 1][j - 1] + A[i][j], B[i - 1][j] + A[i][j]);
			}
		}
		for (i = 0; i < t; i++) {
			temp = max(temp, B[t - 1][i]);
		}
		printf("%d\n", temp);
		temp = 0;
	}
}
