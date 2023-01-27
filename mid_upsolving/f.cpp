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
private:
    Node * root;
    int sum = 0;
    Node * push(Node* cur, int x){
        if(cur == NULL){
            return new Node(x);
        }else if(x < cur->val){
            cur->left = push(cur->left, x);
        }else if(x > cur->val){
            cur->right = push(cur->right, x);
        }
        return cur;
    }

    int sumOfNodes(Node * cur, int level){
        if(cur == NULL){
            return sum; 
        }

        sum += cur->val - level;
        
        sumOfNodes(cur->left, level + 1);
        sumOfNodes(cur->right, level + 1);
    }

public:
    BST(){
        root = NULL;
        sum = 0;
    }


    void push(int x){
        root = push(root, x);
    }


    void sumOfNodes(){
        cout << sumOfNodes(root, 0);
    }
};

int main(){
    int n; cin >> n;
    BST tree;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);

    }
    
    tree.sumOfNodes();

    return 0;
}