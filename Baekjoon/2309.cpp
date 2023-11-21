#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    vector<int> arr;
    int height;
    int sum = 0;
    bool found = false;

    for(int i = 0; i < 9; i++) {
        cin >> height;
        arr.push_back(height);
        sum += height;
    }

    for(int i = 0; i < 9 && !found; i++) {
        for(int j = i + 1; j < 9; j++) {
            if(sum - (arr[i] + arr[j]) == 100) {
                arr.erase(arr.begin() + j); // 먼저 j를 삭제
                arr.erase(arr.begin() + i); // 그 후 i를 삭제
                found = true; // 발견했음을 표시
                break;
            }
        }
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < 7; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

