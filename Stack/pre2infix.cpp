#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
typedef long long int ll;

ll evalRPN(vector<string>& exp){
    stack<ll> s;
    for (int i=exp.size()-1; i>=0; i--){
        if (exp[i]=="+" || exp[i]=="-" || exp[i]=="*" || exp[i]=="/"){
            ll b=s.top();
            s.pop();
            ll a=s.top();
            s.pop();
            if(exp[i] == "+")   s.push(b+a);
            else if(exp[i] == "-")  s.push(b-a);
            else if(exp[i] == "*")  s.push(b*a);
            else    s.push(b/a);
        } else {
            s.push(stoi(exp[i]));
        }
    } return s.top();
}

int main(){
    int n=7;
    vector<string> exp(n);
    for(int i=0;i<n;i++)    cin>>exp[i];
    cout << evalRPN(exp);
    return 0;
}