#include <bits/stdc++.h>
using namespace std;

vector<bool> used;
vector<vector<int>> matrix;
vector<int> dist;

void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s] = true;
    dist[s] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < matrix[v].size(); i++){
            int to = matrix[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
}

int main(){
    int n; cin >> n;
    dist = vector<int>(n);


    return 0;
}