#include <bits/stdc++.h>
using namespace std;


int partition(vector<int> &a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; j++){
        if(a[j] > a[pivot]){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void qsort(vector<int> &a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}


int main(){
    int n, m; 
    cin >> n >> m;
    vector<int> a;
    vector<int> b;


    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        b.push_back(x);
    }

    if(n == 0 || m == 0){
        return 0;
    }

    qsort(a, 0, n - 1);
    qsort(b, 0, m - 1);


    // while (!a.empty() || !b.empty()){
    //     if(a.back() == b.back()){
    //         cout << a.back() << " ";
    //         a.pop_back();
    //         b.pop_back();
    //     }else if(a.back() < b.back()){
    //         a.pop_back();
    //     }else{
    //         b.pop_back();
    //     }
    // }
    int i = n - 1;
    int j = m - 1;
    while(i != -1 && j != -1){
        if(a[i] == b[j]){
            cout << a[i] << " ";
            i--;
            j--;
        }
        else if(a[i] < b[j]){
            i--;
        }else if(b[j] < a[i]){
            j--;
        }
    }
    



}