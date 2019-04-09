#include<iostream>
using namespace std;
bool con[53][53];
double vil[53];
double vil2[53];
int vil_nei[53];
int main() {
	//freopen("input.txt", "r", stdin);
	int t; cin >> t;
	while (t--) {
		int n, d, p; cin >> n >> d >> p;
		char c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				con[i][j] = false;
				cin >> c;
				if (c == '1')
					con[i][j] = true;
			}
		}
		
		for (int i = 0; i < n; i++) {
			//현재 마을
			vil[i] = vil_nei[i] = 0;
			for (int j = 0; j < n; j++) {
				if (con[i][j]) {
					vil_nei[i]++;
				}
			}
		}
		vil[p] = 1;

		while (d--) {
			for (int i = 0; i < n; i++) {
				//현재 마을
				vil2[i] = 0;
				//if (p == i) continue;
				for (int j = 0; j < n; j++) {
					if (con[j][i]) {
						vil2[i] += vil[j]/vil_nei[j];
					}
				}
			}
			for (int i = 0; i < n; i++) {
				vil[i] = vil2[i];
			}
		}

		int len; cin >> len;
		while (len--) {
			int t;  cin >> t;
			printf("%.10lf ", vil[t]);
		}
		cout << endl;
	}
}
