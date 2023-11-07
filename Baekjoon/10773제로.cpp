#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int K;
	cin >> K;
	vector<int> num;
	int number;
	int sum = 0;
	for (int i = 0; i < K; i++) {
		cin >> number;
		if (number == 0) {
			num.erase(num.begin() + num.size() - 1);
		}
		else {
			num.push_back(number);
		}
	}
	for (int i = 0; i < num.size(); i++) {
		sum += num[i];
	}
	cout << sum << endl;
	return 0;
}
