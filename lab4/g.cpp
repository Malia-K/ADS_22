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

struct BST{
    Node * root;
    BST(){
        root = NULL;
    }
    

private:
    
    Node * push(Node * cur, int val){
        if(cur == NULL){
            return new Node(val);
        }
        if(val < cur->val){
            cur->left = push(cur->left, val);
        }
        if(val > cur->val){
            cur->right = push(cur->right, val);
        }

        return cur;
    }


    
public:
    

    void push(int x){
        root = push(root, x);
    }

    int getHeight(Node * cur, int &d){ 
        if (cur == NULL){
            return 0;
        }

        int left = getHeight(cur->left, d);
        int right = getHeight(cur->right, d);
        d = max(d, right + left + 1);

        return max(left, right) + 1;
    }

    int findDiameter(){
        int d = 0;
        getHeight(root, d);
        return d;
    }

};

int main(){
    int n; cin >> n;
    BST tree;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }

    cout << tree.findDiameter();

}