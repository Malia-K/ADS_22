#include <bits/stdc++.h>
using namespace std;

vector<size_t> kmp(string s){
    size_t n = s.size();
    vector<size_t> v(n);
    v[0] = 0;
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

bool isFind(string s, string pattern){
    vector<size_t> ans = kmp(s);

    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == pattern.size()){
            return true;
            
        }
    }
    return false;
}

int main(){
    string text, pattern;
    cin >> text >> pattern;
    int cnt = 1;

    string s = text;
    while(s.size() < pattern.size()){
        s = s + text;
        cnt++;
    }
    s = pattern + '#' + s;
    
    // cout << cnt;
    if(isFind(s, pattern)){
        cout << cnt;
    }else if(isFind(s + text, pattern)){
        cout << cnt + 1;
    }else{
        cout << -1;
    }
    return 0;
}