#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int cnt;

struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

struct LL{
    Node* head;
    Node* tail;
    LL(){
        head = NULL;
        tail = NULL;
    }

    void push(int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            m[newNode->val]++;
        }else{
            tail->next = newNode;
            tail = tail->next;
            m[newNode->val]++;
        }
    }

    void find_max(){
        Node* cur = head;
        while(cur != NULL){
            cnt = max(cnt, m[cur->val]);
            cur = cur->next;
        }

    }

};

int main(){
    int n; cin >> n;
    LL l;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        l.push(x);
    } 
    l.find_max();

    for(auto it = m.rbegin(); it != m.rend(); it++){
        if(it->second == cnt){
            cout << it->first << " ";
        }
    }
    return 0;
}