#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; j++){
        if(v[j] < v[pivot]){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[pivot]);
    return i + 1;
}

void qsort(vector<int> &v, int low, int high){
    if(low < high){
        int pivot = partition(v, low, high);
        qsort(v, low, pivot - 1);
        qsort(v, pivot + 1, high);
    }
}

int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        char x; cin >> x;
        v.push_back(x);
    }
    qsort(v, 0, n - 1);
    char letter; cin >> letter;
    // v.push_back(letter);



    for(int i = 0; i <= n; i++){
        if((char)v[i] > letter){
            cout << (char)v[i];
            return 0;
        }else if(i == n){
            cout << (char)v[0];
            return 0;
        }
    }


}