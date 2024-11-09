#include <iostream>

template<class T>
class Queue {
 private:
    class Node {
    public:
        T data;
        Node* next;
        Node(T data){
            this->data=data;
            this->next=nullptr;
        }
    };
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
 public:
    void enqueue(T data) {
        Node* new_node = new Node(data);
        
        if (tail == nullptr) {
            head = tail = new_node;
            return;
        }
        
        tail->next = new_node;
        tail = new_node;
    }
    
    T dequeue() {
        if (head == nullptr) {
            std::cout << "Queue is empty\n";
            return T();
        }
        
        T data = head->data;
        Node* temp = head;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }
        
        delete temp;
        return data;
    }
    
    T peek() {
        if (head == nullptr) {
            std::cout << "Queue is empty\n";
            return T();
        }
        return head->data;
    }
    
    bool is_empty() {
        return head == nullptr;
    }
    bool is_full() {
        return head != nullptr;
    }
};

int main() {
    Queue<int> q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << q.is_full() << std::endl; 
    std::cout << q.dequeue() << std::endl; // prints 1
    
    std::cout << q.peek() << std::endl; // prints 2
    
    q.enqueue(4);
    q.enqueue(5);
    
    while (!q.is_empty()) {
        std::cout << q.dequeue() << std::endl;
    }
    
    return 0;
}