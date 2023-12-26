//최대 수익 구하기  프로그램
//동적 프로그래밍 이용
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

const int kMaxCnt = 17;

int n, t[kMaxCnt], p[kMaxCnt], d[kMaxCnt], result;

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	//조건 세팅
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		//t[i]: 작업 소요일
		//p[i]: 수익
		scanf_s("%d %d", &t[i], &p[i]);
	}

	//DP 수행
	for (int i = 1; i <= n; i++) {
		//1) i번째 날에 일을 했을 경우
		if (i + t[i] <= n + 1) {
			d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
			//최댓값 갱신
			result = max(result, d[i + t[i]]);
		}
		//2) i번째 날에 일을 하지 않았을 경우
		d[i + 1] = max(d[i + 1], d[i]);
		//최대값 갱신
		result = max(result, d[i + 1]);
	}
	printf("%d\n", result);

	return 0;
}
