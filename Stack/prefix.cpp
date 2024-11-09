#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
typedef long long int ll;

bool isOperator(char c)     {return (!isalpha(c) && !isdigit(c));}
int getPriority(char C){
    if (C == '-' || C == '+')   return 1;
    else if (C == '*' || C == '/')  return 2;
    else if (C == '^')  return 3;
    return 0;
}
string infixToPostfix(string infix){
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;
    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        else if (infix[i] == '(')
            char_stack.push('(');
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();
        }
        else{
            if (isOperator(char_stack.top())){
                if(infix[i] == '^'){
                    while (getPriority(infix[i]) <= getPriority(char_stack.top())){
                        output += char_stack.top();
                        char_stack.pop();
                    }
                } else{
                    while (getPriority(infix[i]) < getPriority(char_stack.top())){
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                char_stack.push(infix[i]);
            }
        }
    } while(!char_stack.empty()){
        output += char_stack.top();
        char_stack.pop();
    } return output;
}
// int prec(char c){
//     if (c == '^')   return 3;
//     else if (c == '/' || c == '*')  return 2;
//     else if (c == '+' || c == '-')  return 1;
//     else    return -1;
// }
// string infixToPostfix(string s){
//     stack<char> st;
//     string result;
//     for (int i = 0; i < s.length(); i++) {
//         char c = s[i];
//         if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
//             result += c;
//         }
            
//         else if (c == '(')      st.push('(');
//         else if (c == ')') {
//             while (st.top() != '(') {
//                 result += st.top();
//                 st.pop();
//             } st.pop();
//         } else {
//             while (!st.empty() && prec(s[i]) <= prec(st.top())) {
//                 result += st.top();
//                 st.pop();
//             } st.push(c);
//         }
//     }
//     while (!st.empty()) {
//         result += st.top();
//         st.pop();
//     }
//     return result;
// } 
string infixToPrefix(string infix){
    int l = infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++) {
        if (infix[i] == '(')    infix[i] = ')';
        else if (infix[i] == ')')   infix[i] = '(';
    } string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main(){
    string s = "((a/b)+c)-(d+(e*f))";
    cout << infixToPostfix(s) << std::endl;
    return 0;
}