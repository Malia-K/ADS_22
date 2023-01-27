#include <bits/stdc++.h>
using namespace std;


int partition(vector<int>  &v, int low, int high){
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
    string v = "aeiou";
    vector<int> vowels;
    vector<int> consonant;

    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(v.find(c) != v.npos){
            vowels.push_back((int)(c - 'a' + 1));
            qsort(vowels, 0, vowels.size() - 1);
        }else{
            consonant.push_back((int)(c - 'a' + 1));
            qsort(consonant, 0, consonant.size() - 1);
        }
    }


    qsort(vowels, 0, vowels.size() - 1);
    // cout << "tg";
    qsort(consonant, 0, consonant.size() - 1);
    // cout << "tg";

    for(int i = 0; i < vowels.size(); i++){
        cout << (char)(vowels[i] + 'a' - 1);
    }

    for(int i = 0; i < consonant.size(); i++){
        cout << (char)(consonant[i]+ 'a' - 1);
    }
}