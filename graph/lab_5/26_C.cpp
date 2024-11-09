#include <bits/stdc++.h>
using namespace std;
int const N=2e5+10;
vector<pair<int,pair<int,int>>> g;
int matrix[100][100];
vector<int> ans(N,INT_MAX);
vector<int> dis(N,INT_MAX);
vector<vector<int>> alter_matrix(100,vector<int>(100,0));
vector<vector<int>> p(100,vector<int>(100,0));

bool bellman_ford(int source){
    
    dis[source]=0;
    for(int i=0;i<source;i++){
        for(auto node:g){
            int start=node.first;
            int end=node.second.first;
            int weight=node.second.second;
            if(dis[start]!=INT_MAX && (dis[start]+weight<dis[end])){
                dis[end]=dis[start]+weight;
            }
        }
    }
    for(auto node:g){
        int start=node.first;
            int end=node.second.first;
            int weight=node.second.second;
            if(dis[start]!=INT_MAX && (dis[start]+weight<dis[end])){
               return false;
            }
    }
    return true;
}
int next_vertex(vector<int>& dist, vector<bool>& visit) {
    int min = INT_MAX;
    int minVertex = 0;
    for (size_t vertex = 0; vertex < dist.size(); vertex++) {
        if (min > dist[vertex] && !visit[vertex]) {
            min = dist[vertex];
            minVertex = vertex;
        }
    }
    return minVertex;
}
void dijkstra(int source, int n){
    vector<bool> vis(n,false);
    vector<int> dist(n,INT_MAX);
    vector<int> ans(n,0);
    dist[source]=0;
    for(int i=0;i<n;i++){
        int next=next_vertex(dist,vis);
        vis[next]=true;
        for(int vertex=0;vertex<n;vertex++){
            if(!vis[vertex]&& matrix[next][vertex]!=0 && dist[vertex]>(dist[next]+alter_matrix[next][vertex])&& dist[next]!=INT_MAX){

                dist[vertex]=dist[next]+alter_matrix[next][vertex];
                
                p[source][vertex]=next;
               
            }
        }
        
    }
    for (int vertex = 0; vertex < n; ++vertex) {
        if(vertex!=source){
            if(dist[vertex]==INT_MAX){
            cout<<source<<" to "<<vertex<<": "<<"infinity"<< endl;
            }
            else{
                cout<<source<<" to "<<vertex<<": "<<dist[vertex]<< endl;
            }
        }
        
        
    }
    // for (int vertex = 0; vertex < n; ++vertex) {
    //      ans[vertex]=dist[vertex]-dis[source]+dis[vertex];
    //     cout<<"OVertex "<<vertex<<": "<<ans[vertex]<<endl;
    // }
}
void johnson(int n){
    for(int i=0;i<n;i++){
        g.push_back({n,{i,0}});
    }
    
    bool ans=bellman_ford(n);
    if(ans==false){
        cout<<"not possible"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0){
                alter_matrix[i][j]=matrix[i][j]+dis[i]-dis[j];
            }
            
        }
    }
    

    for(int i=0;i<n;i++){
        dijkstra(i,n);
    }
    
}
void printpath(int s,int t){
    if(p[s][t]==-1){
        cout<<"no path"<<endl; 
        return;
    }
    else if(p[s][t]==s){
        cout<<s<<"->";
    }
    else{
        printpath(s,p[s][t]);
        printpath(p[s][t],t);
    }
}
int main(){
    freopen("input_C.txt","r",stdin);
    freopen("output.txt","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    int v1,v2,w;
    cin>>v1>>v2>>w;
    if(matrix[v1][v2]>w || matrix[v1][v2]==0){
        g.push_back({v1,{v2,w}});
        matrix[v1][v2]=w;
        p[v1][v2]=v1;
    }
   
}
johnson(n);
// cout<<"modified graph:"<<endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){

//             cout<<alter_matrix[i][j]<<" ";
           
            
//         }
//         cout<<endl;
//     }
//     int start,term;
//     cin>>start>>term;
//     printpath(start,term);
//     cout<<term<<endl;
}
/*
4 5
0 1 -5
0 2 2
0 3 3
1 2 4
2 3 1
*/