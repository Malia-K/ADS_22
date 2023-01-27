#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;
    Node(int x){
        val = x;
        right = left = NULL;
    }
};

class BST{
private:
    Node * root;
    Node * target;

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


    Node* search(Node * cur, int t){
        if(cur != NULL){
            search(cur->left, t);
            search(cur->right, t);
            if(cur->val == t){
                target = cur;
            }
        }
        return target;
    }


    Node * preOrder(Node* cur){
        if(cur != NULL){
            cout << cur->val << " ";
            preOrder(cur->left);
            preOrder(cur->right);
        }
    }

public:

    BST(){
        root = NULL;
    }

    void push(int val){
        root = push(root, val);
    }

    void search(int t){
        target = search(root, t);
    }

    void preOrderPrint(){
        preOrder(target);
    }

    

};


int main(){
    int n; cin >> n;
    BST tree;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }

    int target;
    cin >> target;

    tree.search(target);

    tree.preOrderPrint();


    return 0;
}