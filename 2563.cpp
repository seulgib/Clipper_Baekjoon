//색종이 너비구하기
//겹치는 너비 뺴야함.
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

    int total = LENGTH * LENGTH * n; // 모든 색종이의 총 넓이
    int overlap = 0; // 겹치는 부분의 넓이

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

    cout << total << endl;  // 결과 출력

    return 0;

}