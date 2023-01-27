#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt = 0;

void add_back(string s){
    Node* newNode = new Node(s);
    if(head == NULL){
        head  = newNode;
		tail = newNode;
        cnt++;
    }else{
		newNode->next = NULL;
		tail->next = newNode;
		newNode->prev = tail;
        tail = newNode;
        cnt++;
    }

}
void add_front(string s){
    Node* newNode = new Node(s);
    if(head == NULL){
        head = newNode;
		tail = newNode;
        cnt++;
    }else{
		newNode->prev = NULL;
		head->prev = newNode;
        newNode->next = head;
        head = newNode;
        cnt++;
    }
}
bool empty(){
    if(cnt == 0){
        return true;
    }else{
        return false;
    }
}
void erase_front(){
	if(head == NULL){
		return;
	}else if(head == tail){
		head = tail = NULL;
		cnt = 0;
	}else{
		head = head->next;
		head->prev = NULL;
		cnt--;
	}
}
void erase_back(){
	if(head == NULL){
		return;
	}else if(head == tail){
		head = tail = NULL;
		cnt = 0;
	}else{
		tail = tail->prev;
		tail->next = NULL;
    	cnt--;
	}
    
}
string front(){
	if(head != NULL){
    	return head->val;
	}
}
string back(){
	if(head != NULL){
    	return tail->val;
	}
}
void clear(){
    while(head != NULL){
        head = head->next;
    }
    cnt = 0;
}


// void print(){
//     if(empty()){
//         cout << "empty";
//     }else{
//     Node* cur = head;
//     while(cur!= NULL){
//         cout << cur->val << " ,";
//         cur = cur->next;
//     }
//     }

// }
  
int main()
{
	string s;

   	while(cin >> s){

   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
            // print();
   			cout << "ok" << endl;

   		}
   		else if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
            // print();
   			cout << "ok" << endl;
   		}
   		else if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
                // print();
   			}
   		}
   		else if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
                // print();
   			}
   		}
   		else if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
                // print();
   				cout << front() << endl;
   			}
   		}
   		else if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
                // print();
   				cout << back() << endl;
   			}
   		}
   		else if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		else if(s == "exit"){
            // print();
   			cout << "goodbye" << endl;

   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}