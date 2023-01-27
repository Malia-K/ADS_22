#include <bits/stdc++.h>
#include <vector>
using namespace std;

int hashing(string s, string t){
    size_t n = s.size();
    size_t m = t.size();
    int cnt = 0;

    long long h[n];
    long long p[n];
    p[0] = 1;
    long long q = 1e9 + 7;
    
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
            cnt++;
        }
    }

    return cnt;

}


int main(){

    bool run = true;
    while(run){
        int n; cin >> n;
        if(n == 0){
            run = false;
            break;
        }

        string patterns[n];
        for(int i = 0; i < n; i++){
            cin >> patterns[i];
        }




        string text;cin >> text;


        int mx = -1;
        vector<pair<string,int>> v;

        for(int i = 0; i < n; i++){
            int c = hashing(text, patterns[i]);  
            // cout << patterns[i] << " " << c << endl;          
            if(c > mx){
                mx = c;
            }
            v.push_back(make_pair(patterns[i], c));
        }


        cout << mx << endl;
        for(auto it: v){
            if(it.second == mx){
                cout << it.first << endl;
            }
        }
    }   
}