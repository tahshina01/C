#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;

int start[N];
int low[N];

int t=0;
bool artipoint[N];
vector <int> g[N];
bool vis[N];
void dfs(int vertex,int parent){
    vis[vertex]=true;
    t++;
    start[vertex]=t;
    low[vertex]=t;
    int node=0;
    
    for(int child:g[vertex]){

        if(child == parent) continue;

        else if(!vis[child]){

            dfs(child, vertex);
            low[vertex]=min(low[child],low[vertex]);

            if(low[child]>=start[vertex] && parent!=-1){
                artipoint[vertex]=true;
            }
            node++;

        }

        else{
            //back edge
            low[vertex]=min(low[vertex],start[child]);
            //not take low[child] because we can't reach before child if child is removed
        }
    }
    if(node>1 && parent ==-1){
        artipoint[vertex]=true;
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
    // for(int i=0;i<n;i++){
    //     sort(g[i].begin(),g[i].end());
    // }
    dfs(1,-1);
    int count=0;
    for(int i=0;i<n;i++){
        
        if(artipoint[i]){
            count++;
            cout<<i<<" ";
        }
    }
    cout<<"count "<<count <<endl;
    for(int i=1;i<=n;i++){
        cout<<start[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<low[i]<<" ";
    }
    
} 
/*
7 8
0 1
2 3
0 2
0 3
2 4
2 5
4 6
5 6
*/