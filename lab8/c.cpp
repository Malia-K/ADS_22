#include <bits/stdc++.h>
using namespace std;

vector<int> tape;

void hashing(string s, string t){
    size_t n = s.size();
    size_t m = t.size();
    long long h[n];
    long long p[n];
    p[0] = 1;
    long long q = 2147483647;


    for(size_t i = 1; i < n; i++){
        p[i] = (p[i - 1] * 31) % q;
    }

    for(size_t i = 0; i < n; i++){
        h[i] = ((s[i] - 'a' + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }


    long long h_t = 0;
    for(size_t i = 0; i < m; i++){
        h_t = (h_t + ((t[i] - 'a' + 1) * p[i]) % q ) % q;
    }


    for(size_t i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1];
        if(i > 0){
            d = (d - h[i - 1] + q) % q;
        }
        if(d == (h_t * p[i]) % q){
            // cout << "good1" << endl;
            if(t == s.substr(i, t.size())){
                // cout << "good2" << endl;
                for(size_t j = i; j < i + m; j++){
                    tape[j]++;
                }
            }
        }
    }

}



int main(){
    string s; cin >> s;

    int n; cin >> n;
    tape.resize(s.size());
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        hashing(s, t);
        // cout << 5 << endl;
    }

    bool check = true;
    for(int i = 0; i < tape.size(); i++){
        // cout << i << " " << tape[i] <<endl;
        if(tape[i] == 0){
            check = false;
            break;
        }
    }

    if(check){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}