#include <iostream>
#include <stack>

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
        if(top==-1)return true;
        else return false;
    }
    bool full(){
        if(top==MAX-1)return true;
        else return false;
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

bool validateStackSequence(int pushed[], int popped[], int len){

	int j = 0;
	
	Stack <int> st;
	for(int i = 0; i < len; i++){
		st.push(pushed[i]);
	
		while (!st.empty() && j < len && st.peek() == popped[j]){
			st.pop();
			j++;
		}
	}
	
	return j == len;
}

int main()
{
int pushed[] = {1, 2, 3, 4, 5};
int popped[] = {4, 5, 3, 2, 1};
int len = sizeof(pushed)/sizeof(pushed[0]);
	
cout << (validateStackSequence(pushed, popped, len) ? "True" : "False");
	
return 0;
}
