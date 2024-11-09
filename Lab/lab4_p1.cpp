#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
typedef long long int ll;
int evalRPN(vector<string>& tokens){
    stack<int> s;
    int a,b;
    for(int i=0;i<tokens.size();i++){
        if(tokens[i]=="+"||tokens[i]=="*"||tokens[i]=="-"||tokens[i]=="/"){
            b=s.top();
            s.pop();
            a=s.top();
            s.pop();
            if(tokens[i]=="+"){
                s.push(a+b);
            }
            else if(tokens[i]=="-"){
                s.push(a-b);
            }
            else if(tokens[i]=="*"){
                s.push(a*b);
            }
            else{
                s.push(a/b);
            }
        
        }
        else{
            s.push(stoi(tokens[i]));
        }
    }
    return s.top();
}

int main(){
    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    int n;
    cin>>n;
    vector<string> tokens(n);
    for(int i=0;i<n;i++)    cin>>tokens[i];
    cout << evalRPN(tokens);
    return 0;
}