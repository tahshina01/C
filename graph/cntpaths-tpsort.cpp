#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector <int> g[N];
bool vis[N];
vector<int> s;
void dfs(int vertex){
    
    vis[vertex]=true;
    for(int child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
        //cout<<child<<endl;
    }
    s.push_back(vertex);
}
int countpath(int a,int b){
        vector<int> count(N,0);
        count[a]=1;
        dfs(0);
        reverse(s.begin(),s.end());
        for (int u : s) {
            for (int v : g[u]) {
                count[v] += count[u];
            }
        }
    return count[b];
        
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
    
    cout<<countpath(2,5)<<endl;
    
    
} 

