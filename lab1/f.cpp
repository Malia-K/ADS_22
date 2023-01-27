#include <iostream>
#include <vector>
using namespace std;

vector<int> isPrime(int n){
    vector<int> v;
    bool check = true;

    int i = 2;
    while(v.size()!= n){
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                check = false;
                break;
            }
        }

        if(check ){
            v.push_back(i);
        }
        else{
            check = true;
        }

        i++;
    }

    
    return v;
}

int main(){
    int n; cin >> n;


    vector<int> vprime = isPrime(n);

    
    cout<< vprime[vprime.size() - 1];
    
    return 0;
}