#include <bits/stdc++.h>
using namespace std;

vector<size_t> kmp(string s){
    size_t n = s.size();
    vector<size_t> v(n);
    for(size_t i = 1; i < n; i++){
        size_t j = v[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = v[j - 1];
        }

        if(s[i] == s[j]){
            v[i] = j + 1;
        }
    }

    return v;
}

int main(){
    string text;
    cin >> text;
    vector<size_t> ans = kmp(text);
    // for(int i = 0; i < ans.size() ; i++){
    //     cout << ans[i] << " ";
    // }
    cout << text.size() - ans[ans.size() - 1];
}