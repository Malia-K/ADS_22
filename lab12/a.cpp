#include <bits/stdc++.h>
using namespace std;

int matrix[501][501];
int x[501];
bool used[501];


int main() {
	int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }

	vector <int> ans;

    for(int k = 1; k <= n; k++){
        used[x[k]] = true;
        int temp = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){ 
                matrix[i][j] = min(matrix[i][j], matrix[i][x[k]] + matrix[x[k]][j]);
                if(used[i] && used[j]){
                    temp = max(matrix[i][j], temp);
                }
            }
        }
        ans.push_back(temp);
    }

    for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}