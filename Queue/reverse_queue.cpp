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
void reverse_queue(Queue<std::string>& q){
    if(q.is_empty()){
        return;
    }
    string element = q.peek();
    q.dequeue();
    reverse_queue(q);
    q.enqueue(element);
}
int main(){
    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    Queue<std::string> q;
    q.enqueue("apple");
    q.enqueue("banana");
    q.enqueue("cherry");
    reverse_queue(q);
    while(!q.is_empty()){
        cout<<q.peek()<<endl;
        q.dequeue();
    }
}