#include <iostream>
#include <map>
using namespace std;

struct Node{
    string val;
    Node* next;
    Node(string s){
        val = s;
        next= NULL;
    }
};

struct LinkedList{
    Node* head;
    Node* tail;
    int cnt;

public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        cnt = 0;
    }


    void push_front(string s){
        Node* newNode = new Node(s);

        if(head == NULL){
            head = newNode;
            tail = newNode;
            cnt++;
        }else{

            if(newNode->val.length() == 0 ){ 
                return;
            }
            if(newNode->val == head->val){
                return;
            }

            newNode->next = head;
            head = newNode;
            cnt++;
            
        }
    }

    void print(){
        Node* cur = head;
        cout << "All in all: " << cnt << endl;
        cout << "Students:" << endl;

        while(cur != NULL){
            cout << cur->val << endl;
            cur = cur->next;
        }
    }
};



int main(){
    int n; cin >> n;
    LinkedList l;



    for(int i = 0; i < n; i++){
        string s; cin >> s;

        l.push_front(s);
        
    }

    l.print();
    return 0;
}