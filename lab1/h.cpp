#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number){
    bool check = true;

    if(number == 1) return false;

    for(int i = 2; i <= sqrt(number); i++){
        if(number % i == 0){
            check = false;

        }
    }

    return check;
}

int main(){
    int numberToCheck;
    cin >> numberToCheck;

    if(isPrime(numberToCheck)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}