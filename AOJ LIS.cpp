#include<iostream>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	int t; cin >> t;
	while (t--) {
		int n, arr[504], dp[504]; cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i]; 
			dp[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			dp[i] = 1;
			for (int j = 1; j <= n; j++) {
				if (arr[i] > arr[j]) {
					if (dp[i] < dp[j] + 1) {
						dp[i] = dp[j] + 1;
					}
				}
			}
		}
		int max = 0;
		for (int i = 1; i <= n; i++) {
			if (max < dp[i])max = dp[i];
		}
		cout << max << '\n';
	}
}
