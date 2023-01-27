#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

class BST{
private:
    Node * root;
    int sum = 0;
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

    Node * greaterSum(Node * cur){
        if(cur != NULL){

            greaterSum(cur->right);
            sum += cur->val;
            cur->val = sum;
            // cout << cur->val << " " << sum << endl;
            
            
            greaterSum(cur->left);
        }
        

        return cur;
    }

    Node * inOrder(Node * cur){
        if(cur != NULL){
            inOrder(cur->right);
            cout << cur->val << " ";
            inOrder(cur->left);
            
            
        }
    }

public:
    BST(){
        root = NULL;
    }

    void push(int x){
        root = push(root, x);
    }

    void greaterSum(){
        root = greaterSum(root);
    }


    void inOrder(){
        inOrder(root);
    }
};


int main(){
    int n; cin >> n;
    BST tree;
    for(int i = 0; i < n ; i++){
        int x; cin >> x;
        tree.push(x);
    }


    tree.greaterSum();


    tree.inOrder();



    return 0;
}