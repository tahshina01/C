#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;
vector <int> g[N];
int vis[N]={0};
vector <int> ans;
queue <int> q;
void bfs(int source){
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int next=q.front();
        q.pop();
        ans.push_back(next);
        for(auto it:g[next]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
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
    bfs(0);
    for( int i:ans){
        cout<<i<<endl;
    }
    
} 
