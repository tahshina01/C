#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
typedef long long int ll;

ll evalRPN(vector<string>& exp){
    stack<ll> s;
    for (int i=0; i<exp.size(); i++){
        if (exp[i]=="+" || exp[i]=="-" || exp[i]=="*" || exp[i]=="/"){
            ll b=s.top();
            s.pop();
            ll a=s.top();
            s.pop();
            if(exp[i] == "+")   s.push(a+b);
            else if(exp[i] == "-")  s.push(a-b);
            else if(exp[i] == "*")  s.push(a*b);
            else    s.push(a/b);
        } else{
            s.push(stoi(exp[i]));
        }
    } return s.top();
}

int main(){
    int n=9;
    vector<string> exp(n);
    for(int i=0;i<n;i++)    cin>>exp[i];
    cout << evalRPN(exp);
    return 0;
}