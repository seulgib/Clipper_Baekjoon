//너의 평점은
#include <iostream>
using namespace std;

int main(void) {
    string subject, grade;
    double credit;
    double sumTotal=0, sumCredit = 0;
    double numGrade, average = 0;

    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit>> grade;
        if (grade == "P") continue;
        if (grade[0] == 'A') {
            numGrade = 4.0;
        }
        else if (grade[0] == 'B') {
            numGrade = 3.0;
        }
        else if (grade[0] == 'C') {
            numGrade = 2.0;
        }
        else if (grade[0] == 'D') {
            numGrade = 1.0;
        }
        else if (grade[0] == 'F') {
            numGrade = 0;
        }
        if (grade[1] == '+') {
            numGrade += 0.5;
        }
        sumCredit += credit;
        sumTotal += credit * numGrade;
    }
    average = sumTotal / sumCredit;
    cout << average;
    return 0;
}
