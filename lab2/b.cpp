#include <iostream>
using namespace std;

struct Node{
    string val;
    Node* next;
    Node(string s){
        val = s;
        next =NULL;
    }
};

struct LinkedList{
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void push(string s){
        Node * newNode = new Node(s);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;

            // while(cur != NULL){
            //     if(cur->next == NULL){
            //         cur->next = newNode;
            //         break;
            //     }
            //     cur = cur->next;

            // }
        }
    }
    void shift(int pos){
        
        Node* cur = head;
        while(cur->next != NULL){
            cur = cur->next;
        }

        while(pos != 0){

            cur->next = head;
            head = head->next;
            cur = cur->next;
           
            pos--;
        }
        cur->next = NULL;


        // cur->next = head;
        // cur = head;
        // for(int i = 0; i < pos - 1; i++){
        //     cur = cur->next;
            
        // }
        // head = cur->next;
        // cur->next = NULL;

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
    int n; cin >> n;
    int pos; cin >> pos;
    LinkedList l;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        l.push(s);
    }


    l.shift(pos);
    l.print();
    return 0;
}