#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> dq;
    bool running = true;
    while(running){
        char c; cin >> c;
        if(c == '!'){
            running = false;
        }else if(c == '+'){
            int n; cin >> n;
            dq.push_front(n);
        }else if(c == '-'){
            int n; cin >> n;
            dq.push_back(n);
        }else if(c == '*'){
            if(dq.empty()){
                cout << "error" << endl;
            }else{
                int sum = 0;
                sum = dq.front() + dq.back();
                cout << sum << endl;
                if(dq.size() > 1){
                    dq.pop_back();
                    dq.pop_front();
                }else{
                    dq.pop_front();
                }
            }
                
        }
       
    }
    
    return 0;
}


