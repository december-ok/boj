#include<stdio.h>
#define N 104
int main()
{
	////freopen("input.txt", "r", stdin);
	int t, i, n, now, count, doc, flag;
	int queue[N], front, rear, check[N];
	scanf("%d", &t);
	while (t--) {
		count = front = rear = 0;
		scanf("%d %d", &n, &now);
		for (i = 0; i < n; i++) {//큐 입력
			scanf("%d", &queue[i]);
			check[i] = 0;
			rear = (rear + 1) % N;
		}
		check[now] = 1;
		while (front != rear) {// 큐 시작
			flag = 0;
			doc = queue[front];
			if (front + 1 <= rear) {
				for (i = front + 1; i < rear; i++) {
					if (doc < queue[i]) {
						flag = 1;
						break;
					}
				}
			}
			else {
				for (i = front + 1; i < N + rear; i++) {
					if (i >= N) {
						if (doc < queue[i - N]) {
							flag = 1;
							break;
						}
					}
					else if (doc < queue[i]) {
						flag = 1;
						break;
					}
				}
			}
			if (flag) {
				queue[rear] = queue[front];
				check[rear] = check[front];
				rear = (rear + 1) % N;
			}
			else {
				count++;
				if (check[front]) {
					printf("%d\n", count);
					break;
				}
			}
			front = (front + 1) % N;
		}
	}
}
