#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node* top;
    int size;

    Stack(int size){
        this->size = size;
        this->top = NULL;
    }
    int stack_size(){
     int cnt = 0;
        Node* temp = top;
        while(temp!=NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    void push(int data){
        int cnt = 0;
        Node* temp = top;
        while(temp!=NULL){
            temp = temp->next;
            cnt++;
        }
        if(cnt<size){
            // insert at top
            Node* newNode = new Node(data);
            if(top==NULL){
                top = newNode;
                return;
            }
            else{
                newNode->next = top;
                top = newNode;
            }
        }
        else cout<<"Stack Overflow"<<endl;
    }
    void peak(){
        if(top==NULL) cout<<"stack is empty"<<endl;
        else{
            cout<<top->data<<endl;
        }
    }
    void display(){
        Node* temp = top;
        while(temp){
                cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"display ended"<<endl;
    }

    void pop(){
        if(top==NULL) cout<<"Stack underflow"<<endl;
        else{
            Node* temp = top;
            cout<<"poped element is: "<<temp->data<<endl;
            top = top->next;
            delete temp;
        }
    }
    int stack_search(int d){
        Node* temp = top;
        int cnt=-1;
        while(temp){
                if((temp->data)==d){
                        cnt++;
                    return cnt;
                }
                temp=temp->next;
                cnt++;
        }
        return -1;
    }

    bool isEmpty(){
        if(top==NULL) return true;
        else return false;
    }
    bool isFull(){
        int cnt=0;
        Node* temp = top;
        while(temp!=NULL){
            temp = temp->next;
            cnt++;
        }
        if(cnt==size) return true;
        else return false;
    }
    void stack_clear(){
        top=NULL;
    }
};

int main() {

    Stack s(5);
    s.push(5);
    s.push(15);
    s.push(25);
    s.push(35);
    s.push(45);
    cout<<s.isEmpty()<<endl;
    s.push(5);
    cout<<"relative position "<<s.stack_search(54)<<endl;
    s.display();
    cout<<s.isFull()<<endl;
    s.peak();
    s.pop();

    s.peak();
    s.pop();
    s.display();
    cout<<s.stack_size()<<endl;
s.display();
s.stack_clear();
s.display();
    s.peak();
    s.pop();

    s.peak();
    s.pop();

    s.peak();
    s.pop();

    s.peak();
    s.pop();
    cout<<s.isEmpty()<<endl;
    s.display();
cout<<s.isFull()<<endl;
    return 0;
}
