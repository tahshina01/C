#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
typedef long long int ll;

struct Stack{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct Stack *ptr){
    if (ptr->top == -1) return 1;
    else    return 0;
}
int isFull(struct Stack *ptr){
    if (ptr->top == ptr->size - 1)  return 1;
    else    return 0;
}
void push(struct Stack* ptr, char val){
    if(isFull(ptr)) cout<<"Stack Overflow! Cannot push "<<val<<endl;
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        cout<<"Stack Underflow! Cannot pon"<<endl;
        return -1;
    } else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int parenthesisMatch(string exp){
    // Create and initialize the stack
    struct Stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i]!='\0'; i++){
        if(exp[i]=='(') push(sp, '(');
        else if(exp[i]==')'){
            if(isEmpty(sp)) return 0;
            pop(sp); 
        }
    }
    if(isEmpty(sp)) return 1;
    else    return 0;
}
int main(){
    string exp= ")3+4(8-7)(" ;
    //fgets(exp,100,stdin);
    // Check if stack is empty
    if(parenthesisMatch(exp))   cout<<"The parenthesis is matching"<<endl;
    else    cout<<"The parenthesis is not matching"<<endl;
    return 0;
}
