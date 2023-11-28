#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    vector<string> words;
    string word;
    cin>>word;
    for(int i=0;i<word.length();i++){
        words.push_back(word.substr(i));
    }
    sort(words.begin(), words.end());
    for(int i=0;i<words.size();i++){
        cout<<words[i]<<endl;
    }
    return 0;
}