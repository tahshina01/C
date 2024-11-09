#include<bits/stdc++.h>
using namespace std;

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
    int size = 0;
    const int max_size = 5; // fixed maximum size of the queue
    
 public:
    void enqueue_front(T data) {
        if (size == max_size) {
            std::cout << "Queue is full\n";
            return;
        }
        
        Node* new_node = new Node(data);
        
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        
        size++;
    }
    
    void enqueue_back(T data) {
        if (size == max_size) {
            std::cout << "Queue is full\n";
            return;
        }
        
        Node* new_node = new Node(data);
        
        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        
        size++;
    }
    
    T dequeue_front() {
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
        size--;
        return data;
    }
    
    T dequeue_back() {
        if (tail == nullptr) {
            std::cout << "Queue is empty\n";
            return T();
        }
        
        T data = tail->data;
        
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        
        size--;
        return data;
    }
    
    T peek_front() {
        if (head == nullptr) {
            std::cout << "Queue is empty\n";
            return T();
        }
        return head->data;
    }
    
    T peek_back() {
        if (tail == nullptr) {
            std::cout << "Queue is empty\n";
            return T();
        }
        return tail->data;
    }
    
    bool is_empty() {
        return head == nullptr;
    }
    
    bool is_full() {
        return size == max_size;
    }
    
};
