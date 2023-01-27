#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 1e5 + 1;
vector<int> matrix[MAXN]; 
int color[MAXN];
// bool used[MAXN];
vector<int> ans;

void dfs (int v) {
	if(color[v] == 1){
		cout << "Impossible" << endl;
		exit(0);
	}

	if(color[v] == 2){
		return;
	}

	color[v] = 1;
	// used[v] = true;
	for(int i = 0; i <  matrix[v].size(); i++){
		int to = matrix[v][i];
		// if(!used[v]){
			dfs(to);
		// }
	}
	color[v] = 2;
	ans.push_back(v);
}
 


int main(){
    int m;
    cin >> n >> m;

    while(m--){
        int i, j;
        cin >> i >> j;
        matrix[i].push_back(j);
    }

	for(int i = 1; i <= n; i++){
		if(color[i] == 0){
			dfs(i);
		}
	}

	cout << "Possible" << endl;
	reverse (ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}

    
    return 0;
}