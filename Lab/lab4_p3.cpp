#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
typedef long long int ll;

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

class dinnerplate {
    int cap;
    vector<Stack<int>> stks;
    int leftMost, rightMost;
public:
    dinnerplate(int capacity) {
        cap = capacity;
        leftMost = 0;
        rightMost = 0;
    }
    
    void push(int val) {
        // traverse the leftMost 
        while(leftMost < stks.size() and stks[leftMost].size() == cap) {
            leftMost++;
        }
        
        // at the end
        if(leftMost == stks.size()) {
            Stack<int> stk;
            stk.push(val);
            stks.push_back(stk);
        }
        else { // stack already created
            stks[leftMost].push(val);
        }
        
        // finally update the rightMost value
        rightMost = max(leftMost, rightMost);
    }
    
    int pop() {
        while(rightMost >= 0 and stks[rightMost].empty()) {
            rightMost--;
        }
        
        if(rightMost < 0) return -1;
        
        int top = stks[rightMost].peek();
        stks[rightMost].pop();
        leftMost = min(leftMost, rightMost);
        return top;
    }
    
    int popAtStack(int index) {
        //if the particular stack is not present in stks
        if(stks.size() <= index) {
            return -1;
        }
        
        // if the stack is empty at given index
        if(stks[index].empty()) {
            return -1;
        }
        
        // if stack is not empty then return the value
        int tp = stks[index].peek();
        stks[index].pop();
        
        leftMost = min(leftMost, index);
        
        return tp;
    }
     void display(){
        int i = 0;

        while(i!=rightMost){

            if(stks[i].size()==0){
                i++;
                cout<<endl;
            }

            if(i==-1)return;

            cout<<stks[i].peek()<<" ";
            stks[i].pop();
        }
    }
};

int main(){
    
    vector<string>v = {"DinnerPlates", "push", "push", "push", "push", "push", "popAtStack",
    "push"};

    int a[] = {2,1,2,3,4,5,0,20};

    dinnerplate D =  dinnerplate(a[0]) ;

    for(int i=1;i<v.size();i++){

        if(v[i]=="DinnerPlates"){
            D =  dinnerplate(a[i]) ;
        }
        else{
            if(v[i]=="push"){
                D.push(a[i]);
            }
            else if(v[i]=="pop"){
                D.pop();
            }
            else if(v[i]=="popAtStack"){
                D.popAtStack(a[i]);
            }
        }
    }

    cout<<"display :"<<endl;

    D.display();

    return 0;
}