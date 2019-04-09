#include<iostream>
#define N 1000000007
using namespace std;
int dp[103];
int main() {
	freopen("input.txt", "r", stdin);
	int t; cin >> t;
	dp[0] = dp[1] = 1; dp[2] = 2;
	for (int i = 3; i < 101; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % N;
	}
	while (t--) {
		int n; cin >> n;
		int result;
		if (n % 2) {
			result = (dp[n] + N - dp[n / 2]) % N;
		}
		else {
			result = (dp[n] - (dp[(n / 2) - 1] + dp[n / 2]) % N + N) % N;
		}
		cout << result << endl;
	}
}
