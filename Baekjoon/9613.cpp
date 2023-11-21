/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#define MAX 1000
using namespace std;

int gcd(int x, int y){
    if(x%y==0) return y;
    else return gcd(y, x%y);
}

int main() {
    int arr[MAX];
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;

        for(int j = 0; j < num; j++) {
            cin >> arr[j]; // 배열에 값을 올바르게 할당
        }

        long long sum = 0; // 큰 값이 나올 수 있으므로 long long 사용
        for(int k = 0; k < num; k++) {
            for(int j = k + 1; j < num; j++) {
                sum += gcd(arr[k], arr[j]);
            }
        }

        cout << sum << endl;
    }

    return 0;
}


