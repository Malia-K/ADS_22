#include <bits/stdc++.h>
using namespace std;


int bs(int n, int a[], int x){
    int l = 0; 
    int r = n - 1;

    while(l <= r){
        int m = l + (r - l)/ 2;
        
        if(a[m] <= x){
            l = m + 1;
        }else {
            r = m - 1;
        }

    }
    return l;
}


int main(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n ; i++){
        cin >> a[i];
    }

    sort(a, a + n);


    int r; cin >> r;
    for(int i = 0; i < r; i++){
        int sum = 0;
        int cnt = 0;

        int x; cin >> x;
        int pos = bs(n,a,x);

        for(int i = 0; i < pos; i++){
            sum+= a[i];
            cnt++;
        }

        cout << cnt << " " << sum << endl;
    }
    return 0;
}