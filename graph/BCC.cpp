#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;

int start[N];
int low[N];

int t=0;
bool artipoint[N];
vector <int> g[N];
bool vis[N];
int com=0;
stack<pair<int,int>> edges;
void dfs(int vertex,int parent){
    vis[vertex]=true;
    t++;
    start[vertex]=t;
    low[vertex]=t;
    int node=0;
    
    for(int child:g[vertex]){

        if(child == parent) continue;

        else if(!vis[child]){
             node++;
            edges.push(make_pair(vertex,child));

            dfs(child, vertex);
            low[vertex]=min(low[child],low[vertex]);

                if((parent ==-1 && node>1)||(low[child]>=start[vertex] && parent!=-1)){
                    while(edges.top().first!=vertex || edges.top().second!=child){
                        cout<<edges.top().first<<"--"<<edges.top().second<<" ";
                        edges.pop();
                    }
                    cout<<edges.top().first<<"--"<<edges.top().second<<" ";
                    edges.pop();
                    cout<<endl;
                    com++;
                }
            
           

        }

        else{
            low[vertex]=min(low[vertex],start[child]);
            if(start[child]<start[vertex]){
                edges.push(make_pair(vertex,child));
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
    // for(int i=0;i<n;i++){
    //     sort(g[i].begin(),g[i].end());
    // }
    // for(int i=0;i<n;i++){
        
    //     if(artipoint[i]){
    //         cout<<i<<" ";
    //     }
    // }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1);
            while(!edges.empty()){
                cout<<edges.top().first<<"--"<<edges.top().second<<" ";
                edges.pop();
            }
            cout<<endl;
        }
    }
    cout<<endl;
    
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
/*
5 7
0 3
2 3
1 2
1 4
2 4
4 5
2 5
*/
/*
12 14
0 1
1 2
1 3
2 3
2 4
3 4
1 5
0 6
5 6
5 7
5 8
7 8
8 9
10 11
*/