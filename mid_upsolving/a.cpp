#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

struct BST{
private:
    Node * root;
    vector<int> triangle;

    Node * insert(Node * cur, int x){
        if(cur == NULL){
            return new Node(x);
        }else if (x < cur->val){
            cur->left = insert(cur->left, x);
        }else if(x > cur->val){
            cur->right = insert(cur->right, x);
        }
        return cur;
    }

    int lengthLeft(Node * cur){
        if(cur == NULL){
            return 0;
        }
        return lengthLeft(cur->left) + 1;
    }
    int lengthRight(Node * cur){
        if(cur == NULL){
            return 0;
        }
        return lengthRight(cur->right) + 1;
    }




    void cntTriangle(Node * cur){   
        if(cur == NULL)
            return; 
        // if(cur != NULL){
        
        int left = lengthLeft(cur);
        int right = lengthRight(cur);
        
        while(left != 1 && right != 1){
            // cout << cur->val << " " << left << " " <<  right << endl;
            triangle[min(left, right) - 2]++;
            left--;
            right--;
            
        }

        cntTriangle(cur->left);
        cntTriangle(cur->right);
        // }
         
    }



public:
    BST(int n){
        root = NULL;
        triangle.resize(n - 1);
    }


    void push(int x){
        root = insert(root, x);
    }

    void cntTriangle(){
        cntTriangle(root);

        for(int i = 0; i < triangle.size(); i++){
            cout << triangle[i] << " ";
        }
    }

};

int main(){
    int n; cin >> n;
    BST tree(n);

    for(int i = 0; i < n ; i++){
        int x; cin >> x;
        tree.push(x);
    }

    tree.cntTriangle();


    return 0;
}