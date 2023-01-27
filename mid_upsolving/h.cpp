#include <bits/stdc++.h>
using namespace std;

struct MaxHeap{
    vector<int> heap;
    int cnt = 0;

    int parent(int i ){
        return (i - 1)/ 2;
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
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }




    int compareSons(){
        for(int i = 0; i < heap.size(); i++){
            if(left(i) < heap.size() && right(i)  < heap.size()){
                if(heap[left(i)] < heap[right(i)] ){
                    // cout << heap[left(i)] << " " << heap[right(i)] << endl;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){
    int n; cin >> n;
    MaxHeap heap;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        heap.insert(x);
    }

    cout << heap.compareSons();

    return 0;
}