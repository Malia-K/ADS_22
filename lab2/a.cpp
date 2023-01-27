#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
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

    void push(int x){
        Node* newNode = new Node(x);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
    }

    int diff(int t){
        Node* cur = head;
        int i = 0;
        int min, idOfMin;
        while(cur != NULL){
            cur->val = abs(cur->val - t);
            if(i == 0){
                min = cur->val;
                idOfMin = i;
            }else if(cur->val < min){
                min = cur->val;
                idOfMin = i;
            }
            cur = cur->next;
            i++;
        }

        return idOfMin;
    }

    void print(){
        Node*cur = head;
        while(cur != NULL){
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};


int main(){
    int n; cin >> n;
    LinkedList l;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        l.push(x);
    }
    int t; cin >> t;
    cout << l.diff(t);



    return 0;
} 