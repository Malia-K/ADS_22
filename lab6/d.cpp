#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char delimeter){
    int i = 0;
    int start = 0;
    int end = 0;
    vector<string> ans;
    while(i <= s.length()){
        if(s[i] == delimeter || i == s.length()){
            end = i;
            string substr = "";
            substr.append(s, start, end - start);
            ans.push_back(substr);
            start = end + 1;
        }
        i++;
    }

    return ans;
}



bool checkDate(vector<string> &a, vector<string> &b){
    if (a[2] < b[2]){
        return true;
    }else if(a[2] > b[2]){
        return false;
    }else{
        if(a[1] < b[1]){
            return true;
        }else if(a[1] > b[1]){
            return false;
        }else{
            if(a[0] < b[0]){
                return true;
            }else if(a[0] > b[0]){
                return false;
            }
        }
    }
}

int partition(vector<vector<string>> &a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; j++){
        if(checkDate(a[j], a[pivot])){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void qsort(vector<vector<string>> &a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a,low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main(){
    int n; cin >> n;

    vector<vector<string>> v;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vector<string> spl = split(s, '-');
        v.push_back(spl);
    }

    qsort(v, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << v[i][0] << "-" << v[i][1] << "-" << v[i][2] << endl;
    }


    return 0;
}