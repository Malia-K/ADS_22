#include <bits/stdc++.h>
using namespace std;

void getSubstring(string s){
    size_t n = s.size();

    long long h[n];
    long long p[n];
    long long q = 1e15 + 7;
    p[0] = 1;
    for(size_t i = 1 ; i < n; i++){
        p[i] = (p[i - 1] * 31) % q;
    }
    
    for(size_t i = 0; i < n;i++){
        h[i] =((s[i] - int('a') + 1) * p[i]) % q;

        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q;
        }

        // cout << s[i] << " " << h[i] << endl;
    }


    unordered_map<long long, bool> hashes;
    for(size_t i = 0; i < n; i++){
        long long d = 0;
        long long D = 97;
        for(size_t j = i; j < n; j++){
            d = (d * D + s[j]) % q;
            
            if(hashes.find(d) == hashes.end()){
                hashes[d] = true;
            }
            
        }
    }
    cout << hashes.size();
}


int main(){
    string s; cin >> s;
    getSubstring(s);
    return 0;
}