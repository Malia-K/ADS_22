#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void prime(int n){
    for(int i = 2; i < n;i++){
        bool check = true;
        for(int j = 2; j * j <= i;j++){
            if(i % j == 0){
                check = false;
                break;
            }
        }

        if(check){
            v.push_back(i);
        }
    }
}

int main(){
    int n; cin >> n;
    prime(n);


    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << " ";
    // }
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v.size(); j++){
            if(v[i] + v[j] == n){
                cout << v[i] << " " << v[j];
                return 0;
            }

        }
    }

    return 0;
}