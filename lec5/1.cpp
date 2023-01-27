#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    int cnt;
    node(int x){
        this->val = x;
        this->left = this->right = NULL;
    }
};

struct bst{
    node * root;

    bst(){
        root = NULL;
    }

    node * add(node*cur, int x){
        if(root == NULL){
            node * a = new node(x);
            root = a;
        }else if(cur->val > x){
            if(cur->left == NULL){
                
            }
            add(cur->left, x);
        }
    }


};

int main(){
    int a[] = {10,11,8,5,4,12};

    int n = sizeof(a)/ sizeof(int);

    return 0;
}