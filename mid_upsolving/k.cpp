#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

struct LinkedList{
    Node * head;
    Node * tail;

public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void push(int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void reverse(){
        //
    }


    void print(){
        Node * cur = head;
        while(cur != NULL){
            cout << cur->val << " ";
            cur = cur->next;
        }
    }


};



int main(){
    int q; cin >> q;
    LinkedList l;
    for(int i = 0; i < q; i++){
        int command; cin >> command;
        if(command == 1){
            int x; cin >> x;
            l.push(x);
        }else if(command == 2){
            l.reverse();
        }
    }

    l.print();
    return 0;
}