#include <iostream>
#include <deque>
using namespace std;
int main(){
    int n; cin >> n;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        int size= x;
        deque<int> dq;
        dq.push_front(x);
        
        x -= 1;
        while(x != 0){
            dq.push_front(x);
            int cnt = 0;

            while(cnt != x){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            x -= 1;
        } 
        for(int i = 0; i < size; i++){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }

    return 0;
}