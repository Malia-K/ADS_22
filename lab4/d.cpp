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

    Node * push(Node * cur, int val){
        if(cur == NULL){
            return new Node(val);
        }else if(val < cur->val){
            cur->left = push(cur->left, val);
        }else if(val > cur->val){
            cur->right = push(cur->right, val);
        }
        return cur;
    }

    int height(Node* cur){
        if(cur == NULL)
            return 0;
        else
            return max(height(cur->left), height(cur->right)) + 1;
    }


    void sumOfLevel(Node * cur, int level, int sum[]){
        if(cur == NULL){
            return;
        }

        sum[level] += cur->val;

        sumOfLevel(cur->left, level + 1, sum);
        sumOfLevel(cur->right, level + 1, sum);

    }

public:
    BST(){
        root = NULL;
    }
    void push(int x){
        root = push(root, x);
    }

    void findHeight(){
        cout << height(root) << endl;;
    }

    void print(int arr[], int n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }

    }

    void sumOfLevel(){
        int sum[height(root)] = {0};
        sumOfLevel(root, 0, sum);
        print(sum,height(root));
    }
};


int main(){

    int n; cin >> n;
    BST tree;
    for(int i = 0; i < n ; i++){
        int x; cin >> x;
        tree.push(x);
    }

    tree.findHeight();
    tree.sumOfLevel();
    return 0;
}