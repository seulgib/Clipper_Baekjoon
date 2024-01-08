#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
void add(int num, vector<int>& set) {
	//num�� vector�� �������� �ʴ� ���
	if (find(set.begin(), set.end(), num) == set.end()) {
		set.push_back(num);
	}
}
void remove(int num, vector<int>& set) {
	auto it = remove(set.begin(), set.end(), num);
	set.erase(it, set.end());
}
bool check(int num, vector<int>& set) {
	if (find(set.begin(), set.end(), num) != set.end()) {
		return 1;
	}
	return 0;

}
void toggle(int num, vector<int>& set) {
	//������ �߰�
	if (find(set.begin(), set.end(), num) == set.end()) {
		set.push_back(num);
	}
	//������ ����
	else {
		auto it = remove(set.begin(), set.end(), num);
		set.erase(it, set.end());
	}
}
void all(vector<int>& set) {
	set.clear();
	for (int i = 1; i <= 20; i++) {
		set.push_back(i);
	}
}
void empty(vector<int>& set) {
	set.clear();
}
int main(void) {

	vector<int> set, result;
	int n;
	string instruction, command, snum;
	int num;
	cin >> n;
	cin.ignore();//�ٹٲ� ���� ����
	for (int i = 0; i < n; i++) {
		getline(cin, instruction);
		istringstream iss(instruction);
		iss >> command;
		if (command == "add") {
			//int�� �ڵ���ȯ
			if (iss >> num) {
				add(num, set);
			}

		}
		else if (command == "remove") {
			iss >> num;
			remove(num, set);
		}
		else if (command == "check") {
			iss >> num;
			if (check(num, set))result.push_back(1);
			else result.push_back(0);
		}
		else if (command == "toggle") {
			iss >> num;
			toggle(num, set);
		}
		else if (command == "all") {
			all(set);
		}
		else if (command == "empty") {
			empty(set);
		}
		else {
			cout << "Invalid Instruction." << endl;
		}
	}
	for (int r : result) {
		cout << r << endl;
	}

	return 0;
}
