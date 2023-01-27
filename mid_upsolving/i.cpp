#include <bits/stdc++.h>
using namespace std;


vector<long long> toBin(long long n){
    vector<long long> bin;
    long long i = 0;
    while(n != 0){
        bin.push_back(n % 2);
        n /= 2;
        i++;
    }

    reverse(bin.begin(), bin.end());

    return bin;
}


bool checkForGoodNum(long long n){
    stack<long long> s;
    vector<long long> check = toBin(n);

    for(int i = 0; i < check.size(); i++){
        if(s.empty()){
            s.push(check[i]);
        }
        else if((!s.empty()) && (s.top() == 1 && check[i] == 0)){
            s.pop();
        }else{
            s.push(check[i]);
        }
    }

    if(s.empty()) return true;
    return false; 
}



int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;

        // vector<int> v = toBin(x);
        // for(int i = 0; i < v.size(); i++){
        //     cout << v[i];
        // }
        if(checkForGoodNum(x)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    return 0;
}