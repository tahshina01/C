#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
typedef long long int ll;
int a[1000000];
class Node{
public:
    int data;
    Node* next;

    Node(int data){
    this->data=data;
    this->next=NULL;
    }
    Node(){
    }

    ~Node(){
        int value = this ->data;
        if(this->next !=NULL){
            delete next;
            this->next=NULL;

        }
    }
};
void insertionhead(Node* &head, int d){
    Node* temp= new Node(d);
    temp-> next=head;
    head=temp;

}


    int pairSum(Node* head) {
        Node *ptr=head;
        int n=0,mx=INT_MIN;
        while(ptr!=NULL){
            a[n]=ptr->data;
            ptr=ptr->next;
            n++;
        }
        for(int i=0;i<n/2;i++){
           mx=max((a[i]+a[n-i-1]),mx);

        } return mx;
    }


int main(){
    int n=6;
     Node* node1= new Node(45);
//    cout<<node1->data<<endl;
//    cout<< node1->next<<endl;
    Node* head =node1;
    Node* tail =node1;
    insertionhead(head,1);
    insertionhead(head,3);
    insertionhead(head,5);
    insertionhead(head,3);
    insertionhead(head,5);
    insertionhead(head,6);
    cout<<pairSum(head)<<endl;
    
    return 0;
}
