#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	int multiplicity;
	Node * right;
	Node * left;
	Node(int x){
		val = x;
		multiplicity = 1;
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
	
	Node * isFind(Node * cur, int t){
		if(cur != NULL){
			isFind(cur->left, t);
			isFind(cur->right, t);
			if(cur->val == t){
				target = cur;
			}
		}
		return target;
	}
	
	
	Node * inOrder(Node * cur){
		if(cur != NULL){
			inOrder(cur->left);
			cout << cur->val << " ";
			inOrder(cur->right);
		}
	}
public:
	BST(){
		root = NULL;
        target = NULL;
	}
	
	void push(int x){
		root = push(root, x);
	}
	
	
	
	void isFind(int t){
		target = isFind(root, t);
		if(target != NULL){
			target->multiplicity++;	
		}else{
			push(t);
		}
	}
	
	Node *  search(int t){
		target = isFind(root, t);
		return target;
	}
	
	
	

	void print(){
		inOrder(root);
	}
	
	
};


int main(){
	int n; cin >> n;
	BST tree;
	while(n--){
		string command; cin >> command;
		int val; cin >> val;
		if(command == "insert"){
			tree.isFind(val);
			// tree.print();
		}else if(command == "cnt"){
            Node * target = tree.search(val);
			cout << target->multiplicity << endl;
		}
	}
	return 0;
}
