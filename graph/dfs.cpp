#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;
vector <int> g[N];
bool vis[N];
int links[N];
int k=0;
void dfs(int vertex){
    cout<<vertex<<" ";
    vis[vertex]=true;
    for(int child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
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
        g[v2].push_back(v1);
    }
    
    dfs(0);
    // for(int i=1;i<=n;i++){
    //     if(!vis[i]){
    //         dfs(i);
    //     }
    // }
    
} 
