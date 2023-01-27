#include <bits/stdc++.h>
using namespace std;

struct MinHeap{
    vector<long long> heap;

    long long parent(long long i){
        return (i - 1)/2;
    }

    long long left(long long i){
        return 2*i + 1;
    }
    long long right(long long i){
        return 2*i + 2;
    }

    void insert(long long val){
        heap.push_back(val);

        long long i = heap.size() - 1;

        while(i != 0 && this->heap[parent(i)] > this->heap[i]){
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }

    void heapify(long long i){
        long long l = this->left(i);
        long long r = this->right(i);

        long long smallest = i;

        if(l < this->heap.size() && this->heap[l] < this->heap[i])
            smallest = l;
        if(r < this->heap.size() && this->heap[r] < this->heap[smallest])
            smallest = r;
        if(smallest != i){
            swap(this->heap[i],this->heap[smallest]);
           this->heapify(smallest);
        }
    }


    long long extractMin(){
        if(this->heap.size() == 0) return 0;
        if(this->heap.size() == 1){
            long long root = this->heap[0];
            this->heap.pop_back();
            return root;
        }

        long long root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }

    long long optimize(){
        long long cost = 0;
        while(heap.size() > 1){
            long long min1 = extractMin();
            long long min2 = extractMin();
            long long sum = min1 + min2;
            insert(sum);
            cost += sum;
        }
        return cost;
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
    MinHeap heap;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        heap.insert(x);
    }

    cout << heap.optimize();

    return 0;
}