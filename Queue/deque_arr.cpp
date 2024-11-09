#include<bits/stdc++.h>
using namespace std;
template<class T>
class Deque {
private:
    T* arr;
    int head;
    int tail;
    int front;
    int size;
    int capacity;
public:
    Deque() {
        arr = new T[10]; // Initialize with a capacity of 10
        head = 0;
        tail = -1;
        front = 0;
        size = 0;
        capacity = 10;
    }

    void push_back(T data) {
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
        cout<<"tail "<<tail<<endl;
        arr[tail] = data;
        size++;
    }
    
    void push_front(T data) {
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
        head = (head - 1 + capacity) % capacity;
        arr[head] = data;
        cout<<"head "<<head<<endl;
        size++;
    }

    T pop_back() {
        if (size == 0) {
            std::cout << "Deque is empty\n";
            return T();
        }
        T data = arr[tail];
        tail = (tail - 1 + capacity) % capacity;
        size--;
        return data;
    }
    
    T pop_front() {
        if (size == 0) {
            std::cout << "Deque is empty\n";
            return T();
        }
        T data = arr[front];
        front = (front + 1) % capacity;
        size--;
        return data;
    }

    T peek_front() {
        if (size == 0) {
            std::cout << "Deque is empty\n";
            return T();
        }
        return arr[front];
    }
    
    T peek_back() {
        if (size == 0) {
            std::cout << "Deque is empty\n";
            return T();
        }
        return arr[tail];
    }

    bool is_empty() {
    return (size==0);
    }
    void display(){
        for(int i=head;i<=tail;i++){
            cout<<"data "<<arr[i]<<endl;
        }
    }

};
int main(){
    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    Deque<int> d;
    d.push_front(5);
    d.push_back(6);
    d.push_front(2);
    d.push_back(1);
    d.display();
    cout<<d.peek_back()<<endl;
    cout<<d.peek_front()<<endl;
    d.pop_back();
    cout<<d.peek_back()<<endl;
    cout<<d.is_empty()<<endl;
    

}