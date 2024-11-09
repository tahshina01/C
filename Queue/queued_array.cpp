#include <iostream>
#include <cstdlib>

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

    bool is_empty() {
        return head > tail;
    }
    bool is_full() {
        return head == tail;
    }
};

int main() {
    Queue<int> q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
   // std::cout << q.is_full() << std::endl; 
    std::cout << q.dequeue() << std::endl; // prints 1
    
    std::cout << q.peek() << std::endl; // prints 2
    
    q.enqueue(4);
    q.enqueue(5);
    
    while (!q.is_empty()) {
        std::cout << q.dequeue() << std::endl;
    }
    
    return 0;
}