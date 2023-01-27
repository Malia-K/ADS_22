#include <bits/stdc++.h>
using namespace std;

vector<int> v;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

class BST{
private:
    Node* root;

    
    Node* push(vector<int>& nums, int l, int r){
        if (l > r) return NULL;
        
        int mid = l + (r - l)/2;
        Node* root = new Node(nums[mid]);
        root -> left = push(nums, l, mid - 1);
        root -> right = push(nums, mid + 1, r);
        return root;   
    }

    void inOrder(Node* root){
        if (root == NULL) return;
        inOrder(root -> left);
        v.push_back(root -> val);
        inOrder(root -> right);
    }

    void preOrder(Node* cur){
        if(cur){
            cout << cur -> val << " ";
            preOrder(cur -> left);
            preOrder(cur -> right);
        }
    }

    Node* insert(Node* cur, int val){
        if (!cur) return new Node(val);

        if (val < cur -> val) cur -> left = insert(cur -> left, val);
        if (val > cur -> val) cur -> right = insert(cur -> right, val);

        return cur;
    }

public:
    BST(){
        root = NULL;
    }

    void push(int l, int r){
        root = push(v, l, r);
    }
    void inOrder(){
        inOrder(root);
    }

    
    void insert(int val){
        root = insert(root, val);
    }

    void preOrder(){
        preOrder(root);
    }
};

int main(){
    BST tree;
    int n; cin >> n;
    int size = pow(2, n) - 1;

    for(int i = 0; i < size; i++){
        int x; cin >> x;
        tree.insert(x);
        
    }

    tree.inOrder();
    tree.push(0, v.size()-1);
    tree.preOrder();
}