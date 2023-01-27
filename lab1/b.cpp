#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    stack<int> stack;
    for (int i = 0; i < n; i++){
        cin >> arr[i];

        while((!stack.empty()) && (stack.top() > arr[i])){
            stack.pop();
        }

        if(stack.empty()){
            cout << -1 << " ";
        }
        else{
            cout << stack.top() << " ";
        }

        stack.push(arr[i]);
    }
    return 0;
}