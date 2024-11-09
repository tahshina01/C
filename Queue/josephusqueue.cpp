#include <bits/stdc++.h>
using namespace std;
template<class T>
class Queue {
private:
    T* arr;
    int head;
    int tail;
    int capacity;
public:
    Queue() {
        arr = (T*) malloc(10 * sizeof(T)); // Initialize with a capacity of 10
        head = 0;
        tail = -1;
        capacity = 10;
    }

    void enqueue(T data) {
        if (tail == capacity - 1) {
            // If the array is full, double its size
            T* temp_arr = (T*) malloc(capacity * 2 * sizeof(T));
            for (int i = 0; i < capacity; i++) {
                temp_arr[i] = arr[i];
            }
            free(arr);
            arr = temp_arr;
            capacity *= 2;
        }
        arr[++tail] = data;
    }

    T dequeue() {
        if (head > tail) {
            std::cout << "Queue is empty\n";
            return T();
        }
        return arr[head++];
    }

    T peek() {
        if (head > tail) {
            std::cout << "Queue is empty\n";
            return T();
        }
        return arr[head];
    }
    int size() {
        return tail-head+1;
    }

    bool is_empty() {
        return head > tail;
    }
    bool is_full() {
        return head == tail;
    }
};

void josephus(int n, int k) {
    Queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.enqueue(i);
    }

    while (q.size() > 1) {
        for (int i = 1; i < k; ++i) {
            q.enqueue(q.peek());
            q.dequeue();
        }
       // std::cout << "Eliminated: " << q.peek() << std::endl;
        q.dequeue();
    }

    std::cout << q.peek() << std::endl;
}

int main() {
    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    int n,k,t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        josephus(n, k);
    }
    
    return 0;
}