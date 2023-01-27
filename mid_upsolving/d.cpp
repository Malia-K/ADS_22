#include <bits/stdc++.h>
using namespace std;

void primeCounter(int n){
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            cnt++;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    cout << cnt; 
}
    

int main(){
    int n; cin >> n;
    primeCounter(n);

    return 0;
}