#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;
vector<pair<int,int>> g[N];
int dis[N];
int k=0;
pair<int,int> it;
void sp(int source){
    set<pair<int,int>> pq;
    cout<<" v "<<source<<endl;
    pq.insert({0,source});
    dis[source]=0;

    
    while(!pq.empty()){
        it=*(pq.begin());
        pq.erase(it);
        for(auto next:g[it.second]){
        if(dis[next.first]>(dis[it.second]+next.second)){
            if(dis[next.first]!=INT_MAX){
                pq.erase({dis[next.first],next.first});
            }
            
            dis[next.first]=dis[it.second]+next.second;
            pq.insert({dis[it.second]+next.second,next.first});
        }
    }
        
    }
    
    
}
void clr(int n){
    for(int i=k;i<n+k;i++){
        g[i].clear();
        dis[i]=INT_MAX;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n,m;
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