#include<bits/stdc++.h>
using namespace std;

template<class T> class Node{
 public:
    T data;
    Node <T> *next;
};

template<class T> class Stack{
 private:
    Node <T>*head=NULL, *newnode;
    Node <T>*temp;
    int ct=0;
 public:
    
    void push(T x){
        newnode=new Node<T>();
        newnode->data=x;
        newnode->next=head;
        head=newnode;
        ct++;
    }
    void pop(){
        temp=head;
        head=temp->next;
        delete(temp);
        ct--;
    }
    T peek(){
        if(head==NULL){
            cout<<"No element in stack\n";
            exit(1);
        }
        return head->data;
    }
    bool empty(){
        if(head==NULL)return true;
        else return false;
    }
    int size(){
        return ct;
    }
    bool full(){
        if(ct==500)return true;
        else return false;
    }
    void clear(){
        while(ct!=0){
            temp=head;
            head=temp->next;
            cout<<"temp "<<temp->data<<endl;
            delete(temp);
            ct--;
        }
    }
    void display(){
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    bool search(T x){
        temp=head;
        while(temp!=NULL){
            if(temp->data==x)return true;
            temp=temp->next;
        }
        return false;
    }
};
bool balanced(string exp,Stack<char> stk){
for(int i=0;i<exp.size();i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            stk.push(exp[i]);
        }
        else{
            if((exp[i]==')' && stk.peek()!='(')||(exp[i]=='}' && stk.peek()!='{')||exp[i]==']' && stk.peek()!='['){
                return false;
            }
            else{
                stk.pop();
            }
        }
    }
    return stk.empty();

}
bool isoperand(char c){
    if(c=='+'||c=='-'||c=='/'||c=='*'){
        return true;
    }
    return false;
}
void print(Stack<string>stk){
    if(stk.empty()){
        return;
    }
    print(stk);
    cout<<stk.peek()<<" ";
    stk.pop();
}
string posttoin(string &str,Stack<string> &stk){
    for(int i=0;i<str.size();i++){
        if(isoperand(str[i])){
            string a=stk.peek();
            stk.pop();
            string b=stk.peek();
            string o=to_string(str[i]);
            stk.pop();
            stk.push("("+ b + str[i] + a + ")");
            

        }
        else{
            string a=to_string(str[i]);
            stk.push(a);
        }
    }
    return stk.peek();
}

int main(){
    string exp="({)";
    Stack<char> stk;
    cout<<balanced(exp,stk);

    
}

// int main(){
//     Stack<string> st;
//     for(int i=0;i<5;i++){
//         //int x=rand()%100;
//         string x;
//         cin>>x;
//         //cout<<x<<' ';
//         st.push(x);
//     }
//     //cout<<endl;
//     st.display();
//     st.pop();
//     cout<<st.peek()<<endl;
//     cout<<st.size()<<endl;
//     cout<<st.search("am")<<endl;
//     cout<<st.full()<<endl;
//     st.clear();
//     cout<<st.empty()<<endl;

//     return 0;
// }
