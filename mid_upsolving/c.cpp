#include <bits/stdc++.h>
using namespace std;

struct MaxHeap{
    vector<int> heap;


    int parent(int i){
        return (i - 1)/2;
    }

    int left(int i){
        return 2 * i + 1;
    }

    int right(int i){
        return 2 * i + 2;
    }
    void insert(int x){
        heap.push_back(x);
        int i = heap.size() - 1;

        while(i != 0 && heap[parent(i)] < heap[i] ){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }


    

    int updateHeap(int i, int x){
        i -= 1;
        int target = heap[i] + x;
        heap[i] += x;

        while(i != 0 && heap[parent(i)] < heap[i] ){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
        // print();
        for(int i = 0; i < heap.size(); i++){
            if(heap[i] == target){
                cout << i + 1 << endl;
                break;
            }
        }

    }

    void print(){
        for(int i = 0; i < heap.size(); i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    int n; cin >> n;
    MaxHeap heap;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        heap.insert(x);
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int ind; cin >> ind;
        int x; cin >> x;
        heap.updateHeap(ind,x);
    }

    heap.print();
    return 0;
}