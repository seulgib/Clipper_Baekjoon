//그룹 단어 체커
//그룹 단어:모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우

#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    string word;
    int countGroupWord = n;
    char prevChar;
    for (int i = 0; i < n; i++) {
        char alphabet[26] = { 0, };
        cin >> word;
        //prevChar 새로운 단어 시작될 때 초기화
        char prevChar = word[0];
        //소문자 아스키코드 97
        for (int j = 0; j < word.length(); j++) {
            if (j >= 1) prevChar = word[j - 1];
            alphabet[word[j] - 97]++;
            //그룹단어 배제가 중복되지 않도록, break 넣어주기
            if (alphabet[word[j] - 97] > 1 && prevChar != word[j]) {
                countGroupWord--; break;
            }
        }

    }
    cout << countGroupWord;
    return 0;
}