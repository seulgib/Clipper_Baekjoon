#include <iostream>
#include <stack>
#include <string>
using namespace std;

void isValid(string s) {
    stack<char> stk;

    for(char ch : s) {
        if(ch == '(') {
            stk.push(ch);
        } else {
            if(stk.empty()) {
                return "NO";
            }
            stk.pop();
        }
    }

    if( stk.empty() ) cout<<"YES"<<endl;
    else cout<<"NO";
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        string s;
        cin >> s;
        isValid(s);
    }

    return 0;
}
