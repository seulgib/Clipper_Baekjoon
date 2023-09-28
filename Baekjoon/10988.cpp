//Palindrome 판별 문제
//문자열 길이가 1인 경우->return 0(회문이 아닌걸로 간주.)
#include <iostream>
using namespace std;
int Palindrome(string word) {
    int n = word.length();
    if (word.length() == 1) {
        return 1;
    }
    for (int i = 0; i < n / 2; i++) {
        if (word[i] != word[(n - 1) - i]) {
            return 0;
        }
    }
    return 1;
}
int main(void) {
    string input;
    cin >> input;
    
    cout << Palindrome(input);
    return 0;
}