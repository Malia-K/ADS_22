#include <iostream>
using namespace std;
int main(){
    int n ; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = 0;
    int r = n - 1;

    int x; cin >> x;

    while(l < r){
        int m = l + (r - l) / 2;
        if(a[m] > x){
            r = m - 1;
        }else if(a[m] < x){
            l = m + 1;
        }else if(a[m] == x){
            r = m;
            break;
        }
    }

    if(x == a[r]){
        cout << r;
    }else{
        cout << "not found";
    }
    return 0;
}