#include <iostream>
using namespace std;

int partition(int * a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; j++){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}


void qsort(int * a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, 0, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main(){
    string s;
    cin >> s;

    int a[s.length()];
    for(int i = 0; i < s.length(); i++){
        a[i] = (int)(s[i] - 'a' + 1);
    }

    // for(int i = 0; i < s.length(); i++){
    //     cout << a[i] << " ";
    // }

    qsort(a, 0, s.length() - 1);
    

    for(int i = 0; i < s.length(); i++){
        cout << (char)(a[i] + 'a' - 1);
    }
    return 0;
}