#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;

int start[N];
int low[N];
int finish[N];
int t=0;
vector<pair<int,int>> bridge;
vector <int> g[N];
bool vis[N];
void dfs(int vertex,int parent){
    vis[vertex]=true;
    t++;
    start[vertex]=t;
    low[vertex]=t;
    
    for(int child:g[vertex]){

        if(child == parent) continue;

        else if(!vis[child]){

            dfs(child, vertex);
            low[vertex]=min(low[child],low[vertex]);

            if(low[child]>start[vertex]){
                bridge.push_back(make_pair(child,vertex));
            }

        }

        else{
            low[vertex]=min(low[vertex],low[child]);
        }
    }
    t++;
    finish[vertex]=t;
    
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
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,i);
        }
    }
    cout<<"bridges"<<endl;
    for(int i=0;i<bridge.size();i++){
        cout<<bridge[i].first<<"--"<<bridge[i].second<<endl;
    }
    
} 
/*
12 14
1 2
1 4
2 3
3 4
4 5
5 6
6 7
6 9
7 8
9 8
8 10
10 11
11 12
10 12
*/