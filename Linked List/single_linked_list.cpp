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
int getlength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void deletenode(int position,Node* &head,Node* &tail){
    if(position == 1){
        Node* temp=head;
        head=head ->next;
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
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void insertionhead(Node* &head, int d){
    Node* temp= new Node(d);
    temp-> next=head;
    head=temp;

}
Node* reverselinkedlist(Node* &head,Node* &tail){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr=head;
    Node* forw=NULL;
    tail=head;
    while(curr!=NULL){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    head=prev;
    return prev;
}
int findmiddlenode(Node* head){
    int len=getlength(head);
    int ans=len/2;
    int cnt=0;
    Node* temp=head;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp->data;
}
void uniquelist(Node* &head){
//    if(head==NULL){
//        return NULL;
//    }
     Node* curr = head;

   while(curr->next != NULL){
        if(curr->data == curr->next->data){
            curr->next = curr->next->next;
        }
        else{
            curr = curr->next;
        }
    }
}

Node* duplicateremove(Node* head,Node* &tail){
     if(head == NULL || head->next == NULL){
            return head;
        }
     Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL && curr->next != NULL){
            if(curr->data == curr->next->data){
                while(curr->next != NULL && curr->data == curr->next->data){
                    curr = curr->next;
                }
                if(prev == NULL){
                    head = curr->next;
                }
                else{
                    prev->next = curr->next;
                }
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        tail=prev;

        cout<<" curr "<<prev->data<<endl;
          return head;
}
Node* mergeTwoLists(Node* &list1, Node* list2)
  {
		if(list1==NULL)
        {
        return list2;
		}
		if(list2==NULL)
        {
         return list1;
		}
		if(list1->data<=list2->data)
        {
			list1->next=mergeTwoLists(list1->next,list2);
			return list1;
		}
		else
        {list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}
	}
void reverserecur(Node* &head, Node* &curr,Node* &prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    Node* forw=curr->next;
    reverserecur(head,forw,curr);
    curr->next = prev;
}
void reverses(Node* &head,Node* &tail){
Node* curr = head;
tail = head;
    Node* prev=NULL;
        reverserecur(head,curr,prev);
}
Node* reversem2(Node* &head){
    if(head==NULL||head->next==NULL){
        return head;
    }

    Node* newhead=reversem2(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
void insertiontail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertpositon(Node* &head,Node* &tail, int pos,int d){
    if(pos==1){
        insertionhead(head,d);
        return;
    }
    Node* temp = head;
    int cnt =1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertiontail(tail,d);
        return;
    }
    Node* nodetoinsert =new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1= new Node(45);
//    cout<<node1->data<<endl;
//    cout<< node1->next<<endl;
    Node* head =node1;
    Node* tail =node1;
    Node* node2= new Node(35);
    Node* head2 =node2;
    Node* tail2 =node2;
    print(head);
    print (head2);
    insertiontail(tail2,15);
    print(head2);
    insertionhead(head,12);
    print(head);
    reverselinkedlist(head2,tail2);
     print(head2);
    insertpositon(head, tail, 3, 12);
    print(head);
     insertpositon(head, tail, 3, 45);
    print(head);
    deletenode(4,head,tail);
    print(head);
   reverses(head,tail);
     print(head);
     insertionhead(head,12);
    print(head);
    insertpositon(head2, tail2, 1, 15);
    print(head2);
//uniquelist(head);
print(head);
insertiontail(tail,15);
    print(head);
//    Node* emptynode=mergeTwoLists(head,head2);
//    print(emptynode);
    cout<<" head "<<head->data<<endl;
    cout<<" tail "<<tail->data<<endl;
    //uniquelist(head);
//print(head);
Node* duphead=duplicateremove(head,tail);
print(duphead);
//reverses(head,tail);
     print(head);
    cout<<" head "<<head->data<<endl;
    cout<<" tail "<<tail->data<<endl;
    cout<<" length "<<getlength(head)<<endl;
    cout<<" length "<<findmiddlenode(head)<<endl;

}

