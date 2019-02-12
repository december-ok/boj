#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;
typedef struct lines {
	int v, itc, line;
};
map <int, vector <int>> sta_inf;
map <int, vector <int>> met_map;
map <int, int> visit_sta;
map <int, int> visit_line;
queue <lines> q;
int n, m, t, target, flag, min_itc;
void find1(int v, int itc, int line) {
	int i, j;
	visit_line[line] = 1;
	for (j = 0; j < met_map[line].size(); j++) {
		if (visit_sta[met_map[line][j]] == -1) {
			visit_sta[met_map[line][j]] = itc;
		}
		else {
			visit_sta[met_map[line][j]] = visit_sta[met_map[line][j]] > itc ? itc : visit_sta[met_map[line][j]];
		}
		if (sta_inf[met_map[line][j]].size() > 1 && v != met_map[line][j]) {
			for (i = 0; i < sta_inf[met_map[line][j]].size(); i++) {
				if (line == sta_inf[met_map[line][j]][i] || visit_line[sta_inf[met_map[line][j]][i]] == 1) continue;
				q.push({ met_map[line][j] , itc + 1 ,sta_inf[met_map[line][j]][i] });
			}
		}
	}
}
int main() {
//	freopen("input.txt", "r", stdin);
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (j = 0; j < m; j++) {
			scanf("%d", &t);
			sta_inf[t].push_back(i);
			met_map[i].push_back(t);
			visit_sta[t] = -1;
		}
	}
	scanf("%d", &target);
	for (i = 0; i < sta_inf[0].size(); i++) {
		q.push({ 0,0, sta_inf[0][i] });
	}
	while (!q.empty()) {
		find1(q.front().v, q.front().itc, q.front().line);
		q.pop();
	}
	printf("%d", visit_sta[target]);
}
