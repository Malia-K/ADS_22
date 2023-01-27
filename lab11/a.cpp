#include <bits/stdc++.h> 
using namespace std; 

int n, m; 
int l, r, c; 
vector<pair<int, pair<int, int>>> g; 

int e1[200002]; 
int e2[200002], e3[200002]; 
void col(vector<bool> &used, int l, int r){ 
    for(int i = l; i <= r; i++){
        used[i] = 1; 
    }
} 
int find(int i){ 
    if(i == e1[i]){
        return i; 
    }
    
    return e1[i] = find(e1[i]); 
} 
bool sl(int i, int j){ 
    int a = find(i), b = find(j); 
    if(a == b)return false; 
    e1[a] = b; 
    e2[b] = min(e2[a], e2[b]); 
    e3[b] = max(e3[a], e3[b]); 
    return 1; 
} 
int main(){ 
    cin >> n >> m;  
    vector<bool> used(n, false); 

    while(m--){ 
        cin >> l >> r >> c; 
        l--; r--; 
        g.push_back(make_pair(c, make_pair(l, r))); 
    } 

    for(int i = 0; i < n; i++){ 
        e1[i] = i; 
        e2[i] = i; 
        e3[i] = i; 
 
    } 
    sort(g.begin(), g.end()); 
    long long ans = 0; 
    int cnt = 0, p = -1; 

    for(int i = 0; i < g.size(); i++){ 
        if(cnt > n - 1){
            break;
        }
        int l = g[i].second.first, r = g[i].second.second, c = g[i].first; 
        p = l; 
        for(int j = l; j <= r; j++){ 
            if(j != find(j)){ 
                p = find(j); 
                break; 
            } 
        } 

        if(e2[p] <= l and r <= e3[p]){
            continue; 
        } else if(e2[p] <= r and r <= e3[p]){
            r = e2[p]; 
        }
        else if(e2[p] <= l and l <= e3[p]){
            l = e3[p]; 
        }
        for(int j = l; j <= r; j++){ 
            if(sl(p, j)){ 
                cnt++; 
                ans += c; 
            } 
        } 
    } 
    cout << ans; 
    return 0; 
}