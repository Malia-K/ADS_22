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

struct LinkedList{
    node* head;
public:
    LinkedList(){
        head = NULL;
    }

    void push(int x){
        node* newNode = new node(x);

        if(head == NULL){
            head = newNode;
        }else{
            node* cur = head;

            while(cur != NULL){
                if(cur->next == NULL){
                    cur->next = newNode;
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
            cur = cur->next;
        }
    }
};



int main(){
    LinkedList l;

    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt++;
        
        if(cnt % 2 == 1){
            l.push(x);
        }
    }

    l.print();




    return 0;
}