#include <bits/stdc++.h>
using namespace std;

int findCapacity(int a[], int n, int f){

    int l = 1;
    int r = a[n - 1];

   
    while(l < r){
        int cap = 0;
        int m = l + (r - l) / 2;

        for(int i = 0; i < n; i++){
            cap += ceil(1.0 * a[i] / m);
        }

        if(cap > f){
            l = m + 1;
        }else{
            r = m;
        }
    }
    
    return r;
}

int main(){
    int n; cin >> n;
    int f; cin >> f;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);


    cout << findCapacity(a,n,f);
    return 0;
}