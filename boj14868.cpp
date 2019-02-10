#include<stdio.h>
#include<queue>
using namespace std;
typedef struct land {
	int y, x, civ_n, year;
}land;
queue <land> q, frontq;
int civ[100001];
int map[2003][2003], visit[2003][2003];
int xl[4] = { 0,0,1,-1 };
int yl[4] = { 1,-1,0,0 };
int n, k;
int find(int x) {
	if (x == civ[x]) {
		return x;
	}
	else {
		int y = find(civ[x]);
		civ[x] = y;
		return y;
	}
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	civ[y] = x;
}
int main() {
//	freopen("input.txt", "r", stdin);
	int i, j, flag, year = -1;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= k; i++) {
		civ[i] = i;
	}
	land t, t1;
	for (i = 0; i < k; i++) {
		scanf("%d %d", &t.y, &t.x);
		t.civ_n = i + 1;
		map[t.y][t.x] = t.civ_n;
		t.year = 0;
		frontq.push(t);
	}
	while (!frontq.empty()) {
		t1 = frontq.front();
		frontq.pop();
		for (j = 0; j < 4; j++) {
			if (t1.y + yl[j] > 0 && t1.y + yl[j] <= n) {
				if (t1.x + xl[j] > 0 && t1.x + xl[j] <= n) {
					if (find(t1.civ_n) != find(map[t1.y + yl[j]][t1.x + xl[j]]) && map[t1.y + yl[j]][t1.x + xl[j]]) {
						Union(t1.civ_n, map[t1.y + yl[j]][t1.x + xl[j]]);
					}
				}
			}
		}
		q.push(t1);
	}
	while (!q.empty()) {
		t = q.front();
		q.pop();
		if (year != t.year) {
			flag = 1;
			for (i = 1; i <= k; i++) {
				if (find(1) != find(i)) { 
					flag = 0;
					break;
				}
			}
			if (flag) {
				printf("%d", t.year);
				break;
			}
			year = t.year;
		}
		for (i = 0; i < 4; i++) {
			if (t.y + yl[i] > 0 && t.y + yl[i] <= n) {
				if (t.x + xl[i] > 0 && t.x + xl[i] <= n) {
					if (!map[t.y + yl[i]][t.x + xl[i]]) {
						map[t.y + yl[i]][t.x + xl[i]] = t.civ_n;
						t1.y = t.y + yl[i];
						t1.x = t.x + xl[i];
						t1.year = t.year + 1;
						t1.civ_n = t.civ_n;
						q.push(t1);
						for (j = 0; j < 4; j++) {
							if (t1.y + yl[j] > 0 && t1.y + yl[j] <= n) {
								if (t1.x + xl[j] > 0 && t1.x + xl[j] <= n) {
									if (find(t1.civ_n) != find(map[t1.y + yl[j]][t1.x + xl[j]]) && map[t1.y + yl[j]][t1.x + xl[j]]) {
										Union(t1.civ_n, map[t1.y + yl[j]][t1.x + xl[j]]);
									}
								}
							}
						}
					}
					else if(t.civ_n != map[t.y + yl[i]][t.x + xl[i]]){
						if (find(t.civ_n) != find(map[t.y + yl[i]][t.x + xl[i]])) {
							Union(t.civ_n, map[t.y + yl[i]][t.x + xl[i]]);
						}
					}
				}
			}
		}
	}
}
