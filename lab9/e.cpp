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


// string cutTheString(string s){
//     string pattern = s;
//     int i = 1;
//     int cur = 0;
//     while(s[cur] == s[s.size() - i] && cur + 1 < pattern.size()){
//         cur++;
//         i++;
//     }
//     pattern = s.substr(cur);
//     // cout << pattern << endl;

//     return pattern;
// }

int main(){
    int n; cin >> n;

    for(int i = 0; i < n ; i++){
        string s; cin >> s;
        int m; cin >> m;
        // string res = s  + '#' +  s;
        // string pattern = cutTheString(s);
        string res =  s;
        vector<size_t> ans = kmp(res);
        
        if(res.size() == 1){
            cout << res.size() * m << endl;
        }else{
            int patternSize = ans[ans.size() - 1];
            // cout << pattern << endl;
            cout << (res.size() - patternSize) * (m - 1) + s.size() << endl;

        }
        // while(true){
        //     int cnt = 0;
        //    vector<size_t> ans = kmp(res);
            
        //     for(int i = 0; i < ans.size(); i++ ){
        //         if(ans[i] == s.size()){
        //             cnt++;
        //         }
        //     }

        //     if(cnt >= m){
        //         cout << res.size() - s.size() - 1<< endl;
        //         break;
        //     }
        //     res += pattern;
        // }
    }
}