#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node * right;
    Node * left;
    Node(int x){
        val = x;
        right = left =  NULL;
    }
};


class BST{
private:
    Node * root;
    int cnt = 0;

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

    int check(Node * cur){
        
        if(cur != NULL){
            check(cur->left);

            if(cur->left != NULL && cur->right != NULL){
                cnt++;
            }
            
            check(cur->right);
        }

        return cnt;
    }

public:
    BST(){
        root = NULL;
    }

    void push(int x){
        root = push(root, x);
    }

    void checkTriangle(){
        cout << check(root);
    }
};


int main(){
    int n; cin >> n;
    BST tree;
    for(int i = 0; i < n ; i++){
        int x; cin >> x;
        tree.push(x);
    }

    tree.checkTriangle();
    return 0;
}