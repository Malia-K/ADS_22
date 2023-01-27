#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node * prev;
    Node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }

   
};

class LinkedList{
    Node * head;
    Node * tail;

public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void push(int x){
        Node * newNode = new Node(x);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }


    void print(){
        Node * current = head;
        while(current != NULL){
            cout << current->val << " ";
            current = current->next;
        }
    }

    void del(int t){
        if(head == NULL){
            cout << "empty";
            return;
        }
        if(head->val == t){
            head = head->next;
        }else{
            Node*cur = head;
            Node*prev = NULL;

            while(cur != NULL){
                if(cur->val == t){
                    prev->next = cur->next;
                }

                prev = cur;
                cur = cur->next;
            }
        }
    }
};

int main(){
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);

    list.print();
    return 0;
}