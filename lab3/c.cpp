#include <bits/stdc++.h>
using namespace std;

int bs(int n, int a[], int x, bool isLeft){
    int l = 0; 
    int r = n - 1;

    while(l <= r){
        int mid = l + (r - l)/2;

        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] < x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }

    }
    if(isLeft){
        return l;
    }
    return r;
    
}

int main(){
    int n; cin >> n;
    int q; cin >> q;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    for(int i = 0; i < q; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        bool isIntersection = max(l1,l2) <= min(r1,r2);

        if(isIntersection){
            int ans = bs(n, a, max(r1, r2), false) - bs(n, a, min(l1,l2), true) + 1 ;
            cout << ans << endl;
        }else{
            int ans = bs(n, a, r1, false) - bs(n, a, l1, true) + bs(n,a, r2, false) - bs(n, a, l2, true) + 2 ;
            cout << ans << endl;
        }
    }

    return 0;
}