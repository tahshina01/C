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

bool is_palindrome(std::string str) {
    Queue<char> q;
    // Enqueue each character of the string to the queue
    for (char c : str) {
        q.enqueue(c);
    }
    // Dequeue and compare the characters from the queue and the string
    while (!q.is_empty() && str.length() > 0) {
        if (q.dequeue() != str[0]) {
            return false;
        }
        str = str.substr(1);
    }
    return true;
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    if (is_palindrome(str)) {
        std::cout << "The string is a palindrome\n";
    } else {
        std::cout << "The string is not a palindrome\n";
    }
    return 0;
}
