#include <bits/stdc++.h>
using namespace std;


bool hashing(string s, string t) {
    // cout << s << " " << t << endl;
    int n = s.size();
    int m = t.size();

    long long p[n];
    long long h[n];
    long long q = 2147483647;

    p[0] = 1;
    for(int i = 1; i < max(n, m); i++) {
        p[i] = (p[i - 1] * 31) % q;
    }

    for(int i = 0; i < n; i++) {
        h[i] = ((s[i] - 'a' + 1) * p[i]) % q;
        if(i > 0) h[i] = (h[i] + h[i - 1]) % q;
    }

    long long h_t = 0; 
    for(int i = 0; i < m; i++) {
        h_t = (h_t + ((t[i] - 'a' + 1) * p[i]) % q) % q;
    }

    for(int i = 0; i < n; i++) {
        long long d = h[i + m - 1];
        if(i > 0){
            d = (d - h[i-1] + q) % q;
        }
        if(d == (h_t * p[i]) % q){
            return true;
        }
    }
    return false;
}



int main(){
    int n;
    cin >> n;

    string s[n];
    string min_size;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        if(i == 0){
            min_size = s[i];
        }
        else if(s[i].size() < min_size.size()){
            min_size = s[i];
        }
        // cout << min_size << endl;
    }

    for(int temp = min_size.size() - 1; temp > 0; temp--) {
        for(int i = 0; i + temp < min_size.size(); i++) {
            string cur = min_size.substr(i, temp + 1);
            // cout << temp << endl;
            // bool check = true;
            int j = 0;
            for(j; j < n; j++) {
                if(min_size == s[j]){
                    continue;
                }

                if(!hashing(s[j], cur)) {
                    // check = false;
                    break;
                }
            }
            if(j == n) {
                cout << cur;
                return 0;
            }
        }
    }
    return 0;
}