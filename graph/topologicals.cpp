#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector <int> g[N];
bool vis[N];
void dfs(int vertex,stack<int> &s){
    
    vis[vertex]=true;
    for(int child:g[vertex]){
        if(vis[child]) continue;
        dfs(child,s);
        
    }
    s.push(vertex);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
    }
    stack<int> s;
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
