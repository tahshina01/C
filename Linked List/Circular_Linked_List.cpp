#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;

            }
    }
};
void insertnode(Node* &tail,int element,int d){

    if(tail==NULL){

        Node* newNode= new Node(d);
        tail=newNode;
        newNode->next=newNode;

    }
 
    else{
       
        Node* curr=tail;
       
        while(curr->data!=element){
            curr=curr->next;
       
        }

        Node* temp=new Node(d);
        temp -> next = curr -> next;
        curr->next=temp;
    }
}

void print(Node* &tail){

    Node* temp=tail;
    
    if(tail==NULL){
            cout<<"empty"<<endl;
        return;
    }
    
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    
    cout<<endl;
}
void deletenode(Node* &tail,int d){

    //empty list
    if(tail==NULL){
        cout<<"empty"<<endl;
    }
    
    else{
        Node* prev =tail;
        Node* curr= prev->next;
    
        while(curr->data!=d){
                prev=curr;
            curr=curr->next;
        }
        
        prev->next=curr->next;

        if(curr==prev){
            tail=NULL;
        }

        else if(tail==curr){
            tail=prev;
        }

        curr->next=NULL;
        delete curr;
    }
}
int main(){
    Node* tail=NULL;
    insertnode(tail,5,3);
    print(tail);
    insertnode(tail,3,5);
    print(tail);
    insertnode(tail,5,7);
    print(tail);
    insertnode(tail,3,9);
    print(tail);
    deletenode(tail,3);
    print(tail);

}
