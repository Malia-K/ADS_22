#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; cin >> q;
    deque<int> dq;
    bool reverse = false;
    for(int i = 0; i < q; i++){
        int command; cin >> command;
        if(command == 1){
            if(reverse == false){
                int x; cin >> x;
                dq.push_back(x);
            }else{
                int x; cin >> x;
                dq.push_front(x);
            }
        }else if(command == 2){
            reverse = !reverse;
        }
    }
    
    if(reverse == false){
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }else{
        while(!dq.empty()){
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }


    return 0;
}