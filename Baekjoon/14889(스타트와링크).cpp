#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int N;
int ability[20][20];
bool selected[20];
int answer = INT_MAX;

// 두 팀의 능력치 차이 계산
int calculateDifference() {
    vector<int> teamStart, teamLink;
    for (int i = 0; i < N; ++i) {
        if (selected[i]) teamStart.push_back(i);
        else teamLink.push_back(i);
    }

    int startStat = 0, linkStat = 0;
    for (int i = 0; i < teamStart.size(); ++i) {
        for (int j = 0; j < teamStart.size(); ++j) {
            startStat += ability[teamStart[i]][teamStart[j]];
            linkStat += ability[teamLink[i]][teamLink[j]];
        }
    }
    return abs(startStat - linkStat);
}

// DFS 함수
void dfs(int idx, int count) {
    if (count == N / 2) {
        answer = min(answer, calculateDifference());
        return;
    }

    for (int i = idx; i < N; ++i) {
        if (!selected[i]) {
            selected[i] = true;
            dfs(i + 1, count + 1);
            selected[i] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> ability[i][j];
        }
    }

    dfs(0, 0);
    cout << answer << endl;
    return 0;
}

