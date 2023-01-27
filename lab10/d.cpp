#include <bits/stdc++.h>
using namespace std;

const int mn = 5009;
int black = 0;
int red = 1;

vector<int> matrix[mn];
int min_dist[mn];
int color[mn];
bool used[mn];


void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s] = true;
    min_dist[s]=0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < matrix[v].size(); i++){
            int to = matrix[v][i];
            if(min_dist[to] > min_dist[v] + 1){
                min_dist[to] = min_dist[v] + 1;
                used[to] = true;
                q.push(to);
            }
        }
    }
}



int main(){
    int  n, m, q;
    cin >> n >> m >> q;
    
    for(int i = 1; i <= m; i++){
        int from, to;
        cin >> from >> to;
        matrix[from].push_back(to);
        matrix[to].push_back(from);
    }

    for(int i = 1; i <= n; i++){
        min_dist[i] = 1e9;
    }


    while(q--){
        int command, v;
        cin >> command >> v;
        if(command == 1){
            if(color[v] != red){
                bfs(v);
                color[v] = red;
            }
            
        }else{
            if(min_dist[v] == 1e9){
                cout << -1 << endl;
            }else{
                cout << min_dist[v] << endl;
            }
        }
    }
}