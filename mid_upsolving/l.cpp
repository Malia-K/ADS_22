#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};


class BST{
private:
    Node * root;
    int cnt = 0;
    Node * push(Node * cur, int x){
        if(cur ==  NULL){
            return new Node(x);
        }else if(x < cur->val){
            cur->left = push(cur->left, x);
        }else if(x > cur->val){
            cur->right = push(cur->right, x);
        }
        return cur;
    }


    int cntLeaves(Node* cur){

        if(cur != NULL){
            if(cur->right == NULL && cur->left == NULL){
                cnt++;
            }

            cntLeaves(cur->left);
            cntLeaves(cur->right);
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


    void cntLeaves(){
        cout << cntLeaves(root);
    }

};





int main(){
    int n; cin >> n;
    BST tree;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }

    tree.cntLeaves();
    return 0;
}