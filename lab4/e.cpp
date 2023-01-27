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

class BT{
private:
    Node * root;
    Node * target;

    void pushNode(Node * cur, int val, int direct){
        if(cur == NULL){
            cur = new Node(val);
        }else if(direct == 0){
            cur->left = new Node(val);
        }else{
            cur->right = new Node(val);
        }
        
    }

    Node * search(Node * cur, int val){
        if(cur != NULL){
            if(cur->val == val){
                target = cur;
            }
            search(cur->left, val);
            search(cur->right, val);
        }
        return target;
        
    }

    int height(Node * cur){
        if(cur == NULL){
            return 0;
        }
        else
            return max(height(cur->left), height(cur->right)) + 1;
    }

    int getWidth(Node * cur, int level){
        if(cur == NULL){
            return 0;
        }
        if(level == 1){
            return 1;
        }
        else if(level > 1){
            return getWidth(cur->left, level - 1) + getWidth(cur->right, level - 1);
        }
    } 


    


    int findMaxWidth(Node * cur){
        int maxWidth = 0;
        int curWidth = 0;
        int h = height(cur);
        for(int i = 1; i <= h; i++){
            curWidth = getWidth(cur, i);
            if(curWidth > maxWidth){
                maxWidth = curWidth;
            }
        }

        return maxWidth;
    }

public:
    BT(){
        root = new Node(1);
    }

    void push(int target, int val, int direct){
        Node * cur  = search(root, target);
        pushNode(cur, val, direct);
    }

    void findMaxWidth(){
        cout << findMaxWidth(root);
    }



};


int main(){
    int n; cin >> n;
    BT tree;
    
    
    for(int i = 0; i < n - 1; i++){
        int x, val, direct;
        cin >> x >> val >> direct;

        tree.push(x,val,direct);
    }

    tree.findMaxWidth();

    return 0;
}