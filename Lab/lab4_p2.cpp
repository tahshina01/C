#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
typedef long long int ll;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j=0,n=popped.size();
        for(int a:pushed){
            s.push(a);
            while(!s.empty()&&j<n&&s.top()==popped[j]){
                s.pop();
                j++;
            }
        }return s.empty()&& j==n;
    }

int main(){
    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    int n,a;
    cin>>n;
    vector<int> pushed,popped;
    for(int i=0;i<n;i++){
        cin>>a;
        pushed.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin>>a;
        popped.push_back(a);
    }
    cout << validateStackSequences(pushed,popped);
    return 0;
}