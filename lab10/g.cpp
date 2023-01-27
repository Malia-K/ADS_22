#include <bits/stdc++.h>
using namespace std;

vector<int> matrix[501];
int used[501];
stack<int> st;
vector<int> cyclePath;
bool IsCyclic = false;


bool dfs(int v, int a, int b) {
    used[v] = 1;
    for (int i = 0; i < matrix[v].size(); i++) {
        int to = matrix[v][i];
        if (v == a && b == to){
            continue;
        }
        if (!used[to]) {
            if (dfs(to, a, b)){
                return true;
            }
        }else if (used[to] == 1){
            return true;
        }
    }
    used[v] = 2;
    return false;
}

bool dfs2(int v) {
    used[v] = 1;
    st.push(v);
    for(int i : matrix[v]){
        if(!used[i]){
            if(dfs2(i)){ 
                return true;
            }
        }else if(used[i] == 1){
            while(st.top() != i){
                cyclePath.push_back(st.top());
                st.pop();
            }
            cyclePath.push_back(i);
            cyclePath.push_back(v);
            reverse(cyclePath.begin(), cyclePath.end());
            return true;
        }
    }
    used[v] = 2;
    if (!st.empty()){
        st.pop();
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        matrix[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            IsCyclic = dfs2(i);
            if (IsCyclic)
                break;
        }
    }
    
    if (!IsCyclic) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < cyclePath.size() - 1; i++) {
        int u = cyclePath[i];
        int v = cyclePath[i + 1];
        for (int j = 1; j <= n; j++) {
            used[j] = 0;
        }
        IsCyclic = 0;
        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                IsCyclic |= dfs(j, u, v);
            }
        }
        if (!IsCyclic) {
            cout << "YES" << endl;
            return 0;
        }
    }


    cout << "NO" << endl;
}