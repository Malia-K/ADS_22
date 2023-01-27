#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n; cin >> n;
    queue<char> q;

    for(int i = 0; i < n; i++){
        char x; cin >> x;
        q.push(x);
    }

    int cntS = 0;
    int cntK = 0;

    while(q.size() > 1 && q.size() > cntS && q.size() > cntK){
        if(q.front() == 'K'){
            if(cntK > 0){
                cntK -= 1;
                q.pop();
            }else{
                cntS += 1;
                q.push(q.front());
                q.pop();
            }
        }else{
            if(cntS > 0){
                cntS -= 1;
                q.pop();
            }else{
                cntK += 1;
                q.push(q.front());
                q.pop();
            }
        }
    }


    if(q.front() == 'K'){
        cout << "KATSURAGI";
    }else{
        cout << "SAKAYANAGI";
    }
    return 0;
}