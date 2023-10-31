#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    int n, i;
    double score;
    //사용자 입력(과목 수, 점수)
    cin >> n;
    double arr[n];

    for (i = 0; i < n; i++) {
        cin >> score;
        arr[i] = score;
    }

    double newSum = 0;
    double newArr[n];
    double max_score = 0;
    //최댓값 찾기(STL 사용)
    max_score = *max_element(arr, arr + n);

    //점수 조작
    for (i = 0; i < n; i++) {
        newArr[i] = (arr[i] / max_score) * 100;
        newSum += newArr[i];
    }
    //새 평균
    cout << newSum / n;
    return 0;
}