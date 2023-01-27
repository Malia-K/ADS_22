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
public:
    LinkedList(){
        head = NULL;
    }

    void pushback(int x){
        Node* newNode = new Node(x);
        
        if(head == NULL){
            head = newNode;
        }else{
            Node* cur = head;
            while(cur != NULL){
                if(cur->next == NULL){
                    cur->next = newNode;
                    break;
                }

                cur = cur->next;
            }
        }
    }

    void insert(int data, int pos){
        Node* newNode = new Node(data);

        if (head == nullptr){
            head = newNode;
        }
        else{
            Node* cur = head;
            int i = 1;
            while(cur != NULL){
                if(i == pos){
                    newNode -> next = cur -> next;
                    cur->next = newNode;
                    break;
                }
                cur = cur->next;
                i++;
            }
        }
        
    }

    void pushfront(int x){
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void print(){
        Node* cur = head;
        while(cur != NULL){
            cout << cur -> val << " ";
            cur = cur->next;
        }
    }
};

int main(){
    int n; cin >> n;
    LinkedList l;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        l.pushback(x);
    }

    int data; cin >> data;
    int pos; cin >>pos;

    if(pos == 0){
        l.pushfront(data);
    }else{
        l.insert(data, pos);
    }
    
    l.print();

    return 0;
}