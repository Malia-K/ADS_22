#include <iostream>
using namespace std;

struct node{
    int val;
    node* next;
    node(int x){
        val = x;
        next = NULL;
    }
};

class LinkedList{
    node* head;
public:
    LinkedList(){
        head = NULL;
    }

    void push(int x){
        node* n = new node(x);

        if(head == NULL){
            head = n;
        }
        else{
            node * cur = head;
            while(cur != NULL){
                if(cur->next == NULL){
                    cur->next = n;
                    break;
                }

                cur = cur->next;
            }
        }

    }

    void print(){
        node* cur = head;
        while(cur != NULL){
            cout << cur->val << " ";
            cur =cur->next;
        }
    }


};



int main(){
    LinkedList l;
    int n; cin >> n;


    for(int i = 0; i < n ; i++){
        int x; cin >> x;
        l.push(x);
    }


    l.print();


    return 0;
}