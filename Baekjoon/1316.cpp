//�׷� �ܾ� üĿ
//�׷� �ܾ�:��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ���

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
        //prevChar ���ο� �ܾ� ���۵� �� �ʱ�ȭ
        char prevChar = word[0];
        //�ҹ��� �ƽ�Ű�ڵ� 97
        for (int j = 0; j < word.length(); j++) {
            if (j >= 1) prevChar = word[j - 1];
            alphabet[word[j] - 97]++;
            //�׷�ܾ� ������ �ߺ����� �ʵ���, break �־��ֱ�
            if (alphabet[word[j] - 97] > 1 && prevChar != word[j]) {
                countGroupWord--; break;
            }
        }

    }
    cout << countGroupWord;
    return 0;
}