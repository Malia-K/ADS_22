#include <bits/stdc++.h>
using namespace std;
// KMP algorithm

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
        // cout << v[i] << " ";
    }
    return v;
}


int main(){
    string s, t;
    cin >> s >> t;

    string str = s + '#' + t;
    // cout << str << endl;

    vector<size_t> ans = kmp(str);
    // cout << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    // // cout << endl;

    // for(int i = 0; i < ans.size(); i++){
    //     if(ans[i] == t.size()){
    //         cout << i - (2 * t.size())<< endl;
    //     }
    // }
    return 0;
}