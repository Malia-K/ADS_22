#include <bits/stdc++.h>
using namespace std;

int partition(vector<pair<string, string>> &a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; j++){
        if(a[j].first < a[pivot].first){
            i++;
            swap(a[j], a[i]);
        }

    }

    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void qsort(vector<pair<string, string>> &a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}


int main(){
    int n; cin >> n;
    vector<pair<string, string>> users;
    map<string, string> ans;
    while(n--){
        string oldName, newName;
        cin >> oldName >> newName;
        bool found = false;
        if(users.empty()){
            users.push_back(make_pair(oldName, newName));
        }else{
            for(int i = 0; i < users.size(); i++){
                if(oldName == users[i].second){
                    users[i].second = newName;
                    found = true;
                }
            }

            if(found == false){
                users.push_back(make_pair(oldName, newName));
            }

        }
    }
    
    qsort(users, 0, users.size() - 1);


    cout << users.size() << endl;
    for(int i = 0; i < users.size(); i++){
        cout << users[i].first << " " << users[i].second << endl;
        // ans.insert(users[i]);
    }

    // map<string, string> :: iterator it = ans.begin();
    // cout << users.size() << endl;
    // for(it; it != ans.end(); it++){
    //     cout << it->first << " " << it->second << endl;
    // }


    return 0;
}