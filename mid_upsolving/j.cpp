#include <bits/stdc++.h>
using namespace std;

int bs(int a[], int n, int target, int x){
    int l = 0;
    int r = n - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(x + a[mid] == target){
            return mid;
        }else if(x + a[mid] > target){
            r = mid - 1;
        }else if(x + a[mid] < target){
            l = mid + 1;
        }
    }
    return -1;
}

int main(){
    int target; cin >> target;
    int n; cin >> n;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, n + a);

    for(int i = 0; i < n; i++){
        int index = bs(a, n, target, a[i]);
        if(index != -1){
            cout << a[i] << " " <<  a[index] << endl;
            return 0;
        }
    }

    return 0;
}