#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;

    }
    ~Node(){
    int val=this->data;
    if(next!=NULL){
        delete next;
        next=NULL;
    }
    }
};
void print(Node* head){
Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlength(Node* head){
    int len=0;
Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    return len;
}
void inserthead(Node* &head,Node* &tail,int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head=temp;
        tail=temp;
    }
    else{
         Node* temp = new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }

}
void inserttail(Node* &head,Node* &tail,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp=new Node(d);
    tail->next=temp;
    temp->next=NULL;
    temp->prev=tail;
    tail=temp;
    }

}
void insertposition(Node* &head,Node* &tail, int pos,int d){
    if(pos==1){
        inserthead(head,tail,d);
        return;
    }
    Node* temp = head;
    int cnt =1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        inserttail(head,tail,d);
        return;
    }
    Node* nodetoinsert =new Node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;

}
void deletenode(int position,Node* &head,Node* &tail){
    if(position == 1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr =head;
        Node* prev =NULL;
        int cnt=1;
        while(cnt<position){
                prev=curr;
            curr=curr->next;
        cnt++;

        }
        if(curr->next==NULL){
            tail=prev;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main(){

    //Node* node1= new Node(10);
    //Node* head=node1;
    //Node* tail=node1;
    Node* head=NULL;
    Node* tail=NULL;
    print(head);

    inserthead(head,tail,11);
    print(head);
     inserthead(head,tail,13);
    print(head);
     inserthead(head,tail,15);
    print(head);
    inserttail(head,tail,3);
    print(head);
    insertposition(head,tail,5,100);
    print(head);
    deletenode(5,head,tail);
    print(head);
    cout<<" head "<<head->data<<endl;
    cout<<" tail "<<tail->data<<endl;
    cout<<getlength(head)<<endl;
    return 0;
}
