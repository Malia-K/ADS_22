#include <bits/stdc++.h>
using namespace std;

int bs(double a[], int n, int h){


    int l = 1;
    int r = a[n - 1];

   
    while(l < r){
        int sum = 0;
        int m = l + (r - l) / 2;

        for(int i = 0; i < n; i++){
            sum += ceil(a[i] / m);
        }

        if(sum > h){
            l = m + 1;
        }else{
            r = m;
        }
    }
    
    return r;
}

int main(){
    int n; cin >> n;
    int h; cin >> h;

    double a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);


    cout << bs(a,n,h);
    return 0;
}