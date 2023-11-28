#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

int N;
int storeParent[MAX];
bool visit[MAX];
vector<int> tree[MAX];

void BFS(){
    queue<int> q;
    /*루트노드 1 방문처리하고 q에 push*/
    visit[1]=true;
    q.push(1);
    
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        
        for(int i=0; i<tree[parent].size(); i++){
            int child = tree[parent][i];
            if(!visit[child]){
                storeParent[child] = parent;
                visit[child] = true;
                q.push(child);
            }
        }
    }
}

int main(void){
    cin >> N;
    for(int i=0; i<N-1; i++){ // Node: N개, Edge: N-1개 탐색
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    BFS();
    for(int i=2; i<=N; i++){
        cout << storeParent[i] << "\n";
    }
    return 0;
}

