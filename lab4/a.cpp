#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node * right;
    Node * left;
    Node(int x){
        val = x;
        right = left = NULL;
    }
};


class BST{
public:
    Node * root;

    Node * push(Node * cur, int val){
        if(cur == NULL){
            return new Node(val);
        }else if(val < cur->val){
            cur->left = push(cur->left, val);
        }else{
            cur->right = push(cur->right, val);
        }
        return cur;
    }
    
    bool check(Node * cur, string s){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'L'){
                cur = cur->left;
                if(cur == NULL) return false;
            }else{
                cur = cur->right;
                if(cur == NULL) return false;
            }
        }

        return true;
    }
    

public:
    BST(){
        root = NULL;
    }

    void push(int x){
        root = push(root, x);
    }

    void check(string s){
        if(check(root, s)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
};


int main(){
    int n, q; cin >> n >> q;
    BST tree;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }

    while(q--){
        string s;
        cin >> s;
        tree.check(s);

    }

    return 0;
}