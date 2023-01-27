#include <iostream>
#include <queue>
using namespace std;

struct index{
    int i;
    int j;
    index(int i, int j){
        this->i = i;
        this->j = j;
    }
};

queue<index> q;
int matrix[1000][1000];


void step(int r, int c, int n, int m){
    if(r < n  && c < m && r >= 0 && c >=0 && matrix[r][c] == 1){
        matrix[r][c] = 2;
        q.push(index(r, c));
    }   
}


int main(){
    int n, m;
    cin >> n >> m ;
    int time = -1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> matrix[i][j];
            if(matrix[i][j] == 2){
                q.push(index(i, j));
            }
        }
    }



    while(q.size() > 0){
        time++;
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            index cur = q.front();
            q.pop();

            step(cur.i - 1, cur.j, n, m);
            step(cur.i + 1, cur.j, n, m);
            step(cur.i, cur.j - 1, n, m);
            step(cur.i, cur.j + 1, n, m);
        }
    }

    // for(int i = 1; i <= n; ++i){
    //     for(int j = 1; j <= m; ++j){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(matrix[i][j] == 1){
                cout << -1 << endl;
                return 0;
            }
        }
    }   

    if(time == -1){
        cout << 0 << endl;
    }else{
        cout << time << endl;
    }


    return 0;
}