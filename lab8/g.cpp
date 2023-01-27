#include <bits/stdc++.h>
using namespace std;

int count(string s, string t){
    size_t n = s.size();
    size_t m = t.size();
    long long cnt = 0;
    long long h[n];
    long long p[n];
    p[0] = 1;
    long long q = 1e7 + 7;
    
    for(size_t i = 1; i < n; i++){
        p[i] = (p[i - 1] * 31) % q;
    }

    for(size_t i  = 0; i < n; i++){
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }

    long long h_t = 0;
    for(size_t i = 0; i < m; i++){
        h_t = (h_t + ((t[i] - int('a') + 1) * p[i]) % q) % q;
    }

    for(size_t i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1];

        if(i > 0){
            d = (d - h[i - 1] + q) % q;
        }

        if(d == (h_t * p[i]) % q){
            if(t == s.substr(i, m)){
                cnt++;
            }
            
        }
    }

    return cnt;

}


int main(){
    string s;
    cin >> s;
    int n; cin >> n;
    int l, r;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        // cout << s.substr(l - 1,r - l + 1) << " ";
        cout << count(s, s.substr(l - 1,r - l + 1)) << endl;
    }
   
    return 0;
}