#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    int n, i;
    double score;
    //����� �Է�(���� ��, ����)
    cin >> n;
    double arr[n];

    for (i = 0; i < n; i++) {
        cin >> score;
        arr[i] = score;
    }

    double newSum = 0;
    double newArr[n];
    double max_score = 0;
    //�ִ� ã��(STL ���)
    max_score = *max_element(arr, arr + n);

    //���� ����
    for (i = 0; i < n; i++) {
        newArr[i] = (arr[i] / max_score) * 100;
        newSum += newArr[i];
    }
    //�� ���
    cout << newSum / n;
    return 0;
}