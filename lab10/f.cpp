#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix;
vector<int> color;


void dfs(int v){
    color[v] = 1;
    for(int i : matrix[v]){
        if(color[i] == 0){
            dfs(i);
        }
    }
}


int main(){
    int n,m;
    cin >> n >> m;

    matrix = vector<vector<int>>(n);
    color = vector<int>(n);

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        from--; to--;
        matrix[from].push_back(to);
        matrix[to].push_back(from);
    }



    int s, f;
    cin >> s >> f;
    s--; f--;
    bool check = false;
    dfs(s);
    for(int i = 0; i < n; i++){
        if(color[i] == 1 && i == f ){
            check = true;
        }
    }

    if(check == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }


    return 0;
}