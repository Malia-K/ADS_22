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
		}else if(cur->val == val){
			cur->multiplicity++;
		}else if(val < cur->val){
			cur->left = push(cur->left, val);
		}else{
			cur->right = push(cur->right, val);
		}
		return cur;
	}
	
	Node * search(Node * cur, int t){
		if (cur == NULL) {
			return NULL;
		} else if (cur->val == t) {
			return cur;
		} else if (cur->val < t) {
			return search(cur->right, t);
		} else {
			return search(cur->left, t);
		}
	}

	Node * getMin(Node* cur){
		while(cur->left != NULL){
			cur = cur->left;
		}
		return cur;
	}
	
	Node * deleteNode(Node * cur, int val){
		// cur->multiplicity--;
		if(cur == NULL){
			return NULL;
		}else if(val < cur->val){
			cur->left = deleteNode(cur->left, val);
			return cur;
		}else if(val > cur->val){
			cur->right = deleteNode(cur->right, val);
			return cur;
		}else{
			if(cur->multiplicity == 0){
				if(cur->left == NULL && cur->right == NULL){
					delete cur;
					return NULL;
				}else if(cur->left == NULL){
					Node * temp = cur->right;
					delete cur;
					return temp;
				}else if(cur->right == NULL){
					Node * temp = cur->left;
					delete cur;
					return temp;
				}else{
					Node * temp = getMin(cur->right);
					cur->val = temp->val;
					cur->right = deleteNode(cur->right, temp->val);
					return cur;
				}
			}else{
				cur->multiplicity--;
			}
			return cur;
		}
	}
	
	// Node * inOrder(Node * cur){
	// 	if(cur != NULL){
	// 		inOrder(cur->left);
	// 		cout << cur->val << " ";
	// 		inOrder(cur->right);
	// 	}
	// }
public:
	BST(){
		root = NULL;
        target = NULL;
	}
	
	void push(int x){
		root = push(root, x);
	}
	
	Node *  search(int t){
		target = search(root, t);
		return target;
	}
	
	void deleteNode(int val){
		root = deleteNode(root,val);

	}
	
	// void print(){
	// 	inOrder(root);
	// }
	
};


int main(){
	int n; cin >> n;
	BST tree;
	while(n--){
		string command; cin >> command;
		int val; cin >> val;
		if(command == "insert"){
			tree.push(val);
			// tree.print();
		}else if(command == "cnt"){
            Node * tar = tree.search(val);
			if(tar == NULL){
				cout << 0 << endl;
			}else{
				cout << tar->multiplicity << endl;
			}
		}else if(command == "delete"){
			tree.deleteNode(val);
		}
	}
	return 0;
}