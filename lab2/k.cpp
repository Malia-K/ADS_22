#include <iostream>
#include <map>
using namespace std;

struct Node{
    char val;
    Node * next;
    int cnt;
    Node(char x){
        val = x;
        cnt = 0;
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
    
    void push(char x){
        Node* newNode = new Node(x);
        
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            Node * cur = head;

            while(cur != NULL){
                if(cur->val == x){
                    cur->cnt = 1;
                    return;
                }
                cur = cur->next;
            }   

            tail->next = newNode;
            tail = tail->next;       

        }

    }

    void check_print(){
        Node * cur = head;
        while(cur != NULL){
            if(cur->cnt == 0){
                cout << cur->val << " ";
                return;
            }
            cur = cur->next;
        }
        cout << "-1" << " ";
    }
    


};


int main(){
    int n; cin >> n;
    while(n != 0){
        int m; cin >> m;
        LinkedList l;
        for(int i = 0; i < m ; i++){
            char x; cin >> x;
            l.push(x);
            l.check_print();
        }
        cout << endl;
        n--;

    }

    return 0;
}