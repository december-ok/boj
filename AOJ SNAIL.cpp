#include<iostream>
using namespace std;
int n, m;
double dp[1003][2200];
int main() {
	freopen("input.txt", "r", stdin);
	int t; cin >> t;
	dp[1][1] = 0.25;
	dp[1][2] = 0.75;
	for (int i = 2; i < 1001; i++) {
		for (int j = i; j < 2100; j++) {
			dp[i][j] = 0.75*dp[i - 1][j - 2] + 0.25*dp[i - 1][j - 1];
		}
	}
	while (t--) {
		cin >> n >> m;
		double rst = 0;
		for (int i = n; i < 2100; i++) {
			rst += dp[m][i];
		}
		printf("%.10lf\n", rst);
	}
}
