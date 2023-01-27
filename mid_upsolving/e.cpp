#include <bits/stdc++.h>
using namespace std;

struct stack2_0{
    vector<int> stack;
    int mx = 0;

    void add(int x){
        stack.push_back(x);        
    }

    void del(){
        if(!stack.empty())
            stack.pop_back();
    }

    void getcur(){
        if(!stack.empty()){
            cout << stack.back() << endl;
        }else{
            cout << "error"<< endl;
        }
    }

    void getmax(){
        if(!stack.empty()){
            for(int i = 0; i < stack.size(); i++){
                if(stack[i] > mx){
                    mx = stack[i];
                }
            }
            cout << mx << endl;
            mx = 0;
        }else{
            cout << "error"<< endl;
        }
    }

};



int main(){
    int n; cin >> n;
    stack2_0 s;
    for(int i = 0; i < n; i++){
        string command; cin >> command;
        if(command == "add"){
            int x; cin >> x;
            s.add(x);
        }else if(command == "delete"){
            s.del();
        }else if(command == "getcur"){
            s.getcur();
        }else if(command == "getmax"){
            s.getmax();
        }
    }
    return 0;
}