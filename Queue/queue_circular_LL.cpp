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
    //const int max_size = 5; // fixed maximum size of the queue
    
 public:
    void enqueue(T data) {
        // if (size == max_size) {
        //     std::cout << "Queue is full\n";
        //     return;
        // }
        
        Node* new_node = new Node(data);
        
        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        
        tail->next=head;
        size++;
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
        size--;
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
    
    // bool is_full() {
    //     return size == max_size;
    // }
    int Size(){
        return size;
    }
    
};
void josephus(int n, int k) {
    Queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.enqueue(i);
    }

    while (q.Size() > 1) {
        for (int i = 1; i < k; ++i) {
            q.enqueue(q.peek());
            q.dequeue();
        }
       // std::cout << "Eliminated: " << q.peek() << std::endl;
        q.dequeue();
    }

    cout <<"result"<< q.peek() <<endl;
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