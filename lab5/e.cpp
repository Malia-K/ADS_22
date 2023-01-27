#include <bits/stdc++.h>
using namespace std;

struct MaxHeap{
    vector<long long> heap;
    
    int cnt = 0;

    long long parent(long long i){
        return (i - 1)/2;
    }

    long long left(long long i){
        return 2*i + 1;
    }

    long long right(long long i){
        return 2*i + 2;
    }

    void insert(int val){
        heap.push_back(val);
        long long i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }

        cnt++;
        
    }

    void heapify(long long i){
        long long l = left(i);
        long long r = right(i);
        long long smallest = i;
        if(l < heap.size() && heap[l] > heap[i])
            smallest = l;
        if(r < heap.size() && heap[r] > heap[smallest])
            smallest = r;
        if(smallest != i){
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }


    long long print(int k){
        long long sum = 0;
        if(cnt < k){
            k = cnt;
        }
        for(int i = 0; i < k; i++){
            sum += heap[i];
        }
        return sum;
    }


    void push(int x, int k){
        if(cnt < k)
            insert(x);
        else if(cnt == k && heap[0] < x){
            heap[0] = x;
            heapify(0);
        }
    }


};

int main(){ 
    int q; cin >> q;
    int k; cin >> k;
    MaxHeap heap;

    for(int i = 0; i < q; i++){
        string command;cin >> command;

        if(command == "insert"){
            int x; cin >> x;
            heap.insert(x);
        }
        else if(command == "print"){
            cout << heap.print(k) << endl;
        }
    }
    return 0;
}

