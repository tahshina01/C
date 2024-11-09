
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
    int peak(){
        if(top==NULL){
            cout<<"stack is empty"<<endl;
        } 
        else{
            return top->data;
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
void balanced(int n){
    char c;
Stack s(n+5);
    for(int i=0;i<n;i++){
            cin>>c;
    if(c=='('||c=='{'||c=='['){
        s.push(c);
    }
    else{
        if(c==')'||c=='}'||c==']'){
            if(s.isEmpty()){
                cout<<"imbalanced"<<endl;
                return;
            }
        }
        if((c==')' && s.peak()!='(')||(c=='}' && s.peak()!='{')||(c==']' && s.peak()!='[')){
            cout<<"imbalanced"<<endl;
                return;
        }
        else{
            s.pop();
        }


    }
}
cout<<"balanced"<<endl;
}
int main(){
    int n;
    cin>>n;
    balanced(n);
    return 0;
}
