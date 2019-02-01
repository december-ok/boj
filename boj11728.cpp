#include<stdio.h>
#include<algorithm>
using namespace std;
int a[2000000];
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n + m; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n + m);
	for (i = 0; i < n + m; i++) {
		printf("%d ", a[i]);
	}
}
