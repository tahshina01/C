#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;
vector<pair<int,int>> g[N];
vector<int> path(N,0);
int dis[N];
int k=0;


void sp(int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    cout<<" v "<<source<<endl;
    pq.push({0,source});
    dis[source]=0;

    
    while(!pq.empty()){
        int wt=pq.top().first;
        int vertex=pq.top().second;
        pq.pop();
        for(auto next:g[vertex]){
            int child=next.first;
            int weight=next.second;
        if(dis[child]>(dis[vertex]+weight)){
            dis[child]=dis[vertex]+weight;
            pq.push({dis[vertex]+weight,child});
            path[child]=vertex;
        }
    }
        
    }
    
    
}
void print(int n){
 int current = n;
    
    while (path[current] != current) {
        cout<<current<<" ";
        current = path[current];
    }
    cout<<current<<endl;
}

void clr(int n){
    for(int i=k;i<n+k;i++){
        g[i].clear();
        dis[i]=INT_MAX;
        path[i]=i;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n,m;.4
    cin>>n>>m;
    clr(n);
    for(int i=0;i<m;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        g[v1].push_back({v2,w});
        g[v2].push_back({v1,w});
    }
    int source;
    cin>>source;
    sp(source);
    for(int i=k;i<n+k;i++){
        cout<<i<<" "<<dis[i]<<endl;
    }
    print(3);

    //E*logV
} 
/*
5 6
0 1 2
0 2 1
1 2 1
2 3 2
3 4 1
4 2 2
// node node weight
*/
/*
priority queue
weight node node
*/
/**/