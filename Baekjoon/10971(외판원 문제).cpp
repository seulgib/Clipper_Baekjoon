#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX

using namespace std;

int N, visit[10], graph[10][10], ans = INT_MAX; // ans 초기값을 INT_MAX로 변경

void backTracking(int depth, int start, int prev, int cost) {
	if (depth == N) {
		// 불가능한 경로
		if (graph[prev][start] == 0) return;
		ans = min(ans, cost + graph[prev][start]); // cost를 더해야 함
		return;
	}
	for (int i = 0; i < N; i++) {
		// 이미 방문한 노드거나, 불가능한 경로
		if (visit[i] != 0 || graph[prev][i] == 0) continue;
		visit[i] = 1;
		backTracking(depth + 1, start, i, cost + graph[prev][i]); // cost를 더해야 함
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
