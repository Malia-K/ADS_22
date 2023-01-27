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

        if(s[i] == s[j] || s[i] - s[j] == 32){
            v[i] = j + 1;
        }
    }

    return v;
}

void print(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl; 
    }
}

int main(){
    string text; cin >> text;
    int n; cin >> n;

    vector<pair<string, size_t>> towns(n);
    size_t mx = 0;

    for(int i = 0; i < n; i++){
        string town; cin >> town;
        string pattern = town + '#' + text;
        // cout << pattern << " ";

        vector<size_t> res = kmp(pattern);
        size_t mxlen = res[res.size() - 1];

        mx = max(mx, mxlen);
        towns[i] = make_pair(town, mxlen);
    }

    // cout << mx;

    if(mx == 0){
        cout << 0;
        return 0;
    }

    vector<string> ans;
    for(int i = 0; i < towns.size(); i++){
        if(towns[i].second == mx)
            ans.push_back(towns[i].first);
    }

    cout << ans.size() << endl;
    print(ans);


    return 0;
}