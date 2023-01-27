#include <iostream>
#include <vector>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(head == NULL){
        head = node;
        if(p == 0){
            node->next = head;
            head->next = NULL;
            head = node;
            return head;
        }
    }else if(head != NULL && p == 0){
        node->next = head;
        head = node;
        return head;
    }else{
        Node * cur = head;
        int i = 1;
        while(cur != NULL){
            if(i == p){
                node->next = cur->next;
                cur->next = node;
                break;
            }
            cur= cur->next;
            i++;    
        }
        return head;
    }
}

 
Node* remove(Node* head, int p){
    if(p == 0){
        head = head->next;
        return head;
    }else{
        int i = 0;
        Node* cur = head;
        Node * prev = NULL;
        while(cur != NULL){
            if(i == p){
                prev->next = cur->next;
            }

            prev = cur;
            cur = cur->next;
            i++;
            
        }

        return head;
    }
}
 
Node* replace(Node* head, int p1, int p2){
    if(p1 == p2){
        return head;
    }else{
        Node * cur = head;

        int i = 0;

        while(cur != NULL){
            if(i == p1){
                head = remove(head, p1);
                head = insert(head, cur, p2);
            }
            cur = cur->next;
            i++;
        }

      
        return head;
    }
}
 
Node* reverse(Node* head){
    vector<int> rave;
    Node * cur = head;

    while(cur != NULL){
        rave.push_back(cur->val);
        cur = cur->next;
    }

    cur = head;

    int i = rave.size() - 1;

    while(cur != NULL){
        cur->val = rave[i];
        cur = cur->next;
        i--;
    }

    return head;
}
 
void print(Node* head){
    if(head == NULL){
        cout << "-1" << endl;
        return;
    }
    Node* cur = head;
    while(cur != NULL){
        cout << cur -> val << " ";
        cur = cur->next;
    }
}
 
Node* cyclic_left(Node* head, int x){
    Node * cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }

    while(x != 0){
        cur->next = head;
        head = head->next;
        cur = cur->next;
        x--;
    }

    cur->next = NULL;

    return head;
}
 
Node* cyclic_right(Node* head, int x){
    Node * cur = head;
    int len = 0;

    while(cur->next != NULL){
        cur = cur->next;
        len++;
    }

    x = (len + 1) - x;
    
    while(x != 0){
        cur->next = head;
        head = head->next;
        cur = cur->next;
        x--;
    }

    cur->next = NULL;

    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
            cout << endl;
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}