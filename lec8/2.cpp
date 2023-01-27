#include <bits/stdc++.h>

using namespace std;

bool rabinKarp(string s, string t) {
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

    long long t_h = 0; 
    for(int i = 0; i < m; i++) {
        t_h = (t_h + ((t[i] - 'a' + 1) * p[i]) % q) % q;
    }

    for(int i = 0; i < n; i++) {
        long long d = h[i + m - 1];
        if(i > 0){
            d = (d - h[i-1] + q) % q;
        }
        if(d == (t_h * p[i]) % q){
            return true;
        }
    }
    return false;
}

int main() {
    int k;
    cin >> k;

    string arr[k];
    string pattern;
    for(int i = 0; i < k; i++) {
        cin >> arr[i];
        if(i == 0) pattern = arr[i];
        else if(arr[i].size() < pattern.size()) pattern = arr[i];
    }
    // cout << endl << pattern << endl;

    for(int temp = pattern.size() - 1; temp > 0; temp--) {
        for(int i = 0; i + temp < pattern.size(); i++) {
            string cur = pattern.substr(i, temp + 1);
            int j = 0;
            for(j; j < k; j++) {
                if(pattern == arr[j]) continue;
                if(!rabinKarp(arr[j], cur)) {
                    break;
                }
            }
            if(j == k) {
                cout << cur;
                return 0;
            }
        }
    }
    return 0;
}