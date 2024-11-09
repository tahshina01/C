#include <bits/stdc++.h>
using namespace std;

template<class T>
class Queue {
private:
    T* arr;
    int head;
    int tail;
    int size;
    int capacity;
public:
    Queue() {
        arr = new T[10]; // Initialize with a capacity of 10
        head = 0;
        tail = -1;
        size = 0;
        capacity = 10;
    }

    void addrear(T data) {
        if (size == capacity) {
            // If the array is full, double its size
            T* temp_arr = new T[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                temp_arr[i] = arr[(head + i) % capacity];
            }
            delete[] arr;
            arr = temp_arr;
            head = 0;
            tail = capacity - 1;
            capacity *= 2;
        }
        tail = (tail + 1) % capacity;
        arr[tail] = data;
        size++;
    }

    T removefront() {
        if (size == 0) {
            std::cout << "Queue is empty\n";
            return T();
        }
        T data = arr[head];
        head = (head + 1) % capacity;
        size--;
        return data;
    }

    T peek() {
        if (size == 0) {
            std::cout << "Queue is empty\n";
            return T();
        }
        return arr[head];
    }

    bool is_empty() {
        return size == 0;
    }

    bool is_full() {
        return size == capacity;
    }
};

int main() {
    Queue<int> q;
    
    
    
   
    
    return 0;
}