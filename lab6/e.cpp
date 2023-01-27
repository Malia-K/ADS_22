#include <bits/stdc++.h>
using namespace std;


struct column{
    vector<int> items;

    void append(int x){
        this->items.push_back(x);
    }

    void sort(){
        qsort(items, 0, this->items.size() - 1);
    }

    void print(int j){
        cout << this->items[j] << " ";
        // for(int i = 0; i < items.size(); i++){
        //     cout << items[i] << " ";
        // }
        // cout << endl;
    }


    int partition(vector<int> &a, int low, int high){
        int i = low - 1;
        int pivot = high;
        for(int j = low; j <= high - 1; j++){
            if(a[j] > a[pivot]){
                i++;
                swap(a[i], a[j]);
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

    
};



int main(){
    int n, m; 
    cin >> n >> m;

    column a[m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            int x; cin >> x;
            a[j].append(x);
        }
    }


    for(int j = 0; j < m; j++){
        a[j].sort();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            a[j].print(i);
        }
        cout << endl;
    }

    // for(int j = 0; j < m ; j++){
    //     a[j].print(j);
        
    // }

    
}