#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s; cin >> s;
    stack<char> stack;
    for (int i = 0; i < s.length(); i++){
        if(stack.empty()){
            stack.push(s[i]);
        }else if((!stack.empty()) && stack.top() != s[i]){
            stack.push(s[i]);
        }else if((!stack.empty()) && stack.top() == s[i]){
            stack.pop();
        }

    }
    
    if(stack.size() == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}