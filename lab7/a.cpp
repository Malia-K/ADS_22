#include <bits/stdc++.h>
using namespace std;


void split(vector<string> &a, string s, char delimeter){
    int start = 0;
    int end = 0;
    int i = 0;

    while(i <= s.length()){
        if(s[i] == delimeter || i == s.length()){
            end = i;
            string substr = "";
            substr.append(s,start, end - start);
            a.push_back(substr);
            start = end + 1;
        }
        i++;
    }
    

}

void merge(vector<string> &a, int l1, int r1, int l2, int r2){
    int n1 = r2 - l2 + 1;
    string L[n1];
    for(int i = 0; i < n1; i++){
        L[i] = a[l2 + i];
    }

    int n2 = r1 - l1 + 1;
    string R[n2];
    for(int i = 0; i < n2; i++){
        R[i] = a[l1 + i];
    }


    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 && i2 < n2){
        if(L[i1].size() < R[i2].size()){
            a[i++] = L[i1++];
        }else{
            a[i++] = R[i2++];
        }
    }

    while(i1 < n1){
        a[i++] = L[i1++];
    }

    while(i2 < n2){
        a[i++] = R[i2++];
    }

}


void msort(vector<string> &a, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        msort(a, l, mid);
        msort(a, mid + 1, r);
        merge(a, l, mid, mid + 1, r);
    }
}

int main(){
    int n; cin >> n;
    cin.ignore();
    // vector<vector<string>> v;
    while(n--){
        vector<string> spl;
        // while(true){
        //     string s; cin >> s;
        //     spl.push_back(s);
        //     if(cin.get() == '\n')
        //        break;
        // }
        string s;
        getline(cin, s);
        split(spl, s, ' ');
        msort(spl, 0, spl.size() - 1);
        for(int j = 0; j < spl.size(); j++){
            cout << spl[j] << " ";
        }
        cout << endl;
        // v.push_back(spl);
    }



    // int i = 0;
    // while(n--){
    //     msort(v[i], 0, v[i].size() - 1);
    //     for(int j = 0; j < v[i].size(); j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    //     i++;
    // }
    return 0;
}