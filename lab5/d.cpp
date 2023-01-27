#include <bits/stdc++.h>
using namespace std;

struct MinHeap{
    vector<int> heap;
    int parent(int i){
        return (i  - 1)/2;
    }
    int left(int i){
        return 2*i + 1;
    }
    int right(int i){
        return 2*i + 2;
    }

    void insert(int val){
        heap.push_back(val);

        int i = heap.size() - 1;

        while(i != 0 && heap[parent(i)] > heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap.size() && heap[l] < heap[i])
            smallest = l;
        if(r < heap.size() && heap[r] < heap[smallest])
            smallest = r;
        if(smallest != i){
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    int extractMin(){
        if(heap.size() == 0) return 0;
        if(heap.size() == 1){
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }

    int mixtures(int m){
        int cnt = 0;
        bool allValid = false;

        while(heap.size() > 1){
            int d_least = extractMin();
            int d_sec_least = extractMin();

            if(d_least >= m){
                return cnt;
            }

            int d = d_least + 2*d_sec_least;
            // cout <<"d: " <<  d << " ";
            // if(d >= m){
            //     cnt++;
                // cout << cnt << endl;
            // }
            cnt++;
            insert(d);
    
            // print();
        }

        return -1;

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
    int m; cin >> m;
    MinHeap heap;

    for(int i = 0; i < n;i++){
        int x; cin >> x;
        heap.insert(x);
    }

    cout << heap.mixtures(m);

    return 0;
}
