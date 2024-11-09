#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector <int> g[N];
bool vis[N];
void dfs(int vertex,stack<char> &s){
    
    vis[vertex]=true;
    for(int child:g[vertex]){
        if(vis[child]) continue;
        dfs(child,s);
        //cout<<child<<endl;
    }
    s.push(vertex+'a');
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        char v1,v2;
        cin>>v1>>v2;
        g[v1-'a'].push_back(v2-'a');
    }
    stack<char> s;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,s);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    
} 
/*
1 2
1 3
2 4
5 6
4 6
4 5
3 4
*/
/*
a b
a c
b d
e f
d f
d e
c d
*/