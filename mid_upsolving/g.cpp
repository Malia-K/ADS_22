#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    deque<int> pingpong;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(pingpong.empty()){
            pingpong.push_back(x);
        }else{
            if(x - pingpong.front() <= 3000){
                pingpong.push_back(x);
            }else{
                pingpong.push_back(x);
                while(x - pingpong.front() > 3000){
                    // cout << pingpong.front() << endl;
                    pingpong.pop_front();
                } 
            }
        }
        ans.push_back(pingpong.size());
    }


    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}