#include<iostream>
using namespace std;
int error[1000];//0이면 가능 1이면 불가능
int compst(int a, int b) {
	int a1 = a / 100, a2 = (a / 10) % 10, a3 = a % 10;
	int b1 = b / 100, b2 = (b / 10) % 10, b3 = b % 10;
	int result = 0;
	if (a1 == b1) result++;
	if (a2 == b2) result++;
	if (a3 == b3) result++;
	return result;
}
int compbl(int a, int b) {
	int a1 = a / 100, a2 = (a / 10) % 10, a3 = a % 10;
	int b1 = b / 100, b2 = (b / 10) % 10, b3 = b % 10;
	int result = 0;
	if (a1 == b2 || a1 == b3) result++;
	if (a2 == b1 || a2 == b3) result++;
	if (a3 == b1 || a3 == b2) result++;
	return result;
}
int main() {
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 0; i < 1000; i++) {
		int a = i / 100, b = (i / 10) % 10 , c = i % 10;
		if (a == b || b == c || c == a || a == 0 || b == 0 || c == 0) error[i] = 1;
	}
	int check[100][3];
	for (int i = 0; i < n; i++) cin >> check[i][0] >> check[i][1] >> check[i][2];
	for (int i = 0; i < 1000; i++) {
		if (error[i]) continue;
		else {
			for (int j = 0; j < n; j++) {
				if (compst(i, check[j][0]) != check[j][1] || compbl(i, check[j][0]) != check[j][2]) {
					error[i] = 1; break;
				}
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 1000; i++) {
		if (!error[i])count++;
	}
	cout << count;
}
