#include <bits/stdc++.h>
using namespace std;

vector<char> unhashing(long long *h, int n){
    long long p[n];
    p[0] = 1;
    for(size_t i = 1; i < n; i++){
        p[i] = (p[i - 1] * 2);
    }
    // cout << "good" << endl;
    vector<char> ans(n);

    for(size_t i = 0; i < n; i++){

        ans[i] = ((h[i] / p[i]) + 97);
        // cout << ans[i];
        if(i > 0){
            ans[i] = ((h[i] - h[i - 1])/ p[i]) + 97;
        }
        // cout << ans[i] << endl;
        ans[i] = (char)ans[i];
    }

    return ans;

}


int main(){
    int n; cin >> n;

    long long h[n];
    for(size_t i = 0; i < n; i++){
        cin >> h[i];
    }

    vector<char> ans = unhashing(h, n);
    for(int i = 0; i < n; i++){
        cout << ans[i];
    }

    return 0;
}