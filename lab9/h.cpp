#include <bits/stdc++.h>
using namespace std;

vector<size_t> kmp(string s){
    size_t n = s.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i++){
        size_t j = v[i - 1];
        while(j > 0 && s[j] != s[i]){
            j = v[j - 1];
        }

        if(s[i] == s[j]){
            v[i] = j + 1;
        }
    }
    return v;
}

int main(){
    string text; cin >> text;
    vector<size_t> ans = kmp(text);
    int cnt = 0;
    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << " ";
    // }

    // cout << endl;
    for(int i = 1; i < ans.size(); i++ ){
        // cout << ans[i] << " ";
        if(i % 2 == 0){
            int k = i - ans[i - 1];
            if((i / k ) % 2 == 0){
                cnt++;
                // cout << cnt ;
            }
            // cout << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}