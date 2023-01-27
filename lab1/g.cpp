#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num){
    bool b = true;
    if( num == 1){
        b = false;
    }

    for(int i = 2; i * i <= num; i++ ){
        if(num % i == 0){
            b = false;
            break;
        }
    }
    return b;
}


vector<int> vecOfPrime(int n){
    vector<int> v;
    int i = 2;

    while(v.size()!= n + 1){
        if(isPrime(i) ){
            v.push_back(i);
            // cout << i << " ";
        }

        i++;
    }

    return v;
}


vector<int> isSuperPrime(vector<int> v){
    vector<int> superV;

    for(int i = 0; i < v.size(); i++){
        // cout << endl << i << " " << v[i];
        if(isPrime(i + 1)){
            superV.push_back(v[i]);
            // cout << v[i] << " ";
        }
    }
    
    return superV;
}

int main(){
    int n; cin >> n;
    vector<int> vPrime = vecOfPrime(n * n);

    vector<int> superPrime = isSuperPrime(vPrime);

    cout<< superPrime[n - 1];
    
    
    return 0;
}