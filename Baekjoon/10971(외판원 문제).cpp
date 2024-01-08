#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX

using namespace std;

int N, visit[10], graph[10][10], ans = INT_MAX; // ans �ʱⰪ�� INT_MAX�� ����

void backTracking(int depth, int start, int prev, int cost) {
	if (depth == N) {
		// �Ұ����� ���
		if (graph[prev][start] == 0) return;
		ans = min(ans, cost + graph[prev][start]); // cost�� ���ؾ� ��
		return;
	}
	for (int i = 0; i < N; i++) {
		// �̹� �湮�� ���ų�, �Ұ����� ���
		if (visit[i] != 0 || graph[prev][i] == 0) continue;
		visit[i] = 1;
		backTracking(depth + 1, start, i, cost + graph[prev][i]); // cost�� ���ؾ� ��
		visit[i] = 0;
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		backTracking(1, i, i, 0);
		visit[i] = 0;
	}
	printf("%d\n", ans);
	return 0;
}
