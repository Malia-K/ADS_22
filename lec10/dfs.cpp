#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix;
vector<int> color;
vector<bool> used;
vector<int> time_in, time_out;
int dfs_timer = 0;



void dfs(int v){
    time_in[v] = dfs_timer++;
    color[v] = 1;// цвет что мы вошли в него
    used[v] = true;
    cout << v << " ";
    for(int i : matrix[v]){
        if(matrix[v][i] > 0 && color[i] == 0){
            dfs(i);
        }
    }

    color[v] = 2;// цвет что мы обработали его
    time_out[v] = dfs_timer++;

}


int main(){
    int n;
    cin >> n;
    matrix = vector<vector<int>>(n, vector<int>(n, 0));
    color = vector<int>(n, 0);
    used = vector<bool>(n, false);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int b; cin >> b;
            matrix[i][j] = b;
            matrix[j][i] = b;
        }
    }

    // dfs(0);

    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }




    return 0;
}