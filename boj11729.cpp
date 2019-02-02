#include<stdio.h>
#include<math.h>
void move(int num, int x, int y) {
	if (!num)return;
	move(num - 1, x, (6 - x) - y);
	printf("%d %d\n", x, y);
	move(num - 1, (6 - x) - y, y);

}
int main()
{
/////	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)pow(2, n) - 1);
	move(n, 1, 3);
}
