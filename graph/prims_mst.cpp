//n nodes
//n-1 edges
//everynode is reachable from every other node
#include<bits/stdc++.h>
using namespace std;
int k=0;
const int N= 2e5+10;
vector<pair<int,int>> g[N];
bool vis[N];
int sum=0;
int mst(){
    vector<pair<int,int>> tree;
    vector<pair<pair<int,int>,int>> mstree;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,-1}});
    
    while(pq.size()){//o(e*loge)
        auto vertex =pq.top();
        pq.pop();
        int weight= vertex.first;
        int node=vertex.second.first;
        int parent=vertex.second.second;
        if(vis[node]) continue;
        if(parent!=-1){
            tree.push_back({parent,node});
            mstree.push_back({{parent,node},weight});
        }
        vis[node]=true;
        sum+=weight;
        
        //cout<<node<<" sum "<<sum<<" parent "<<vertex.second.second<<endl;
        for(auto child: g[node]){//o(e*loge)
            int newvertex=child.first;
            int wt=child.second;

            if(!vis[newvertex]){
                pq.push({wt,{newvertex,node}});//o(loge)
            }
        }
    }
    // printing mst
    cout<<"nodes"<<"\t"<<"weight"<<endl;
        for(auto it : mstree){
            cout<<it.first.first<<"-"<<it.first.second<<" \t"<<it.second<<endl;
        }
    return sum;
}
void clr(int n){
    for(int i=k;i<n+k;i++){
        g[i].clear();
        vis[i]=false;
    }
    sum=0;
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
    int ans=mst();
    cout<<"total weight "<<ans<<endl;
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