#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int t; cin >> t;

    int l = 0;
    int r = n - 1;


    while(l < r){
        int m = l + (r - l)/2;

        if(a[m] > t){
            r = m - 1;
        }else if(a[m] < t){
            l = m + 1;
        }else if(a[m] == t){
            r = m;
            break;
        }
    }

    if(a[r] == t){
        cout << "Yes";
    }else{
        cout << "No";
    }



    return 0;
}