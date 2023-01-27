#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    stack<char> stack1;
    stack<char> stack2;

    for(int i = 0; i <= s1.length(); i++){
        if(s1[i] != '#'){
            stack1.push(s1[i]);
        }else{
            stack1.pop();
        } 
    }

    for(int i = 0; i <= s2.length(); i++){
        if(s2[i] != '#'){
            stack2.push(s2[i]);
        }else{
            stack2.pop();
        } 
    }


    if(stack1 == stack2){
        cout<< "Yes";
    }else{
        cout << "No";
    }

    return 0;
}