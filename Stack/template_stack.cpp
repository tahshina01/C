#include<bits/stdc++.h>
using namespace std;

#define MAX 500

template<class T> class Stack{
 private:
    int top=-1;
    T ar[MAX];
 public:
    void push(T x){
        if(top==MAX-1)cout<<"Stack is Full\n";
        else{
            top++;
            ar[top]=x;
        }
    }
    void pop(){
        if(top==-1)cout<<"Stack empty\n";
        else{
            top--;
        }
    }
    T peek(){
        if(top==-1){
            cout<<"No element in stack\n";
            return -1;
        }
        else{
            return ar[top];
        }
    }
    bool empty(){
        return (top==-1);
    }
    bool full(){
        return (top==MAX-1);
    }
    int size(){
        return top+1;
    }
    void clear(){
        top=-1;
    }
    T search(T x){
        for(int i=0;i<=top;i++){
            if(ar[i]==x)return i;
        }
        return -1;
    }
    void display(){
        for(int i=top;i>=0;i--){
            cout<<ar[i]<<' ';
        }
        cout<<endl;
    }
};

int main(){
    Stack<int> st;
    for(int i=0;i<5;i++){
        int x=rand()%100;
        st.push(x);
    }
    st.display();
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.size()<<endl;
    cout<<st.search(1)<<endl;
    cout<<st.full()<<endl;
    st.clear();
    cout<<st.empty()<<endl;


    return 0;
}