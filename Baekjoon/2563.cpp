//������ �ʺ��ϱ�
//��ġ�� �ʺ� ������.
#include <iostream>
#include <vector>
#include <cmath>
#define LENGTH 10
using namespace std;
int main(void) {
    int n;
    cin >> n;
    vector <pair< int, int >> input(n);
    
    int first, second;

    for (int i = 0; i < n; i++) {
        std::cin >> first >> second;
        input[i] = { first, second };
    }
    //...

    int total = LENGTH * LENGTH * n; // ��� �������� �� ����
    int overlap = 0; // ��ġ�� �κ��� ����

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int leftOverlap = max(input[i].first, input[j].first);
            int rightOverlap = min(input[i].first + LENGTH, input[j].first + LENGTH);
            int bottomOverlap = max(input[i].second, input[j].second);
            int topOverlap = min(input[i].second + LENGTH, input[j].second + LENGTH);

            if (leftOverlap < rightOverlap && bottomOverlap < topOverlap) {
                int overlapWidth = rightOverlap - leftOverlap;
                int overlapHeight = topOverlap - bottomOverlap;
                overlap += overlapWidth * overlapHeight;
            }
        }
    }

    total -= overlap;

    cout << total << endl;  // ��� ���

    return 0;

}