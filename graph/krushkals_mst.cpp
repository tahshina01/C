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

class DisjointSets {
private:
    vector<int> parent, rank;

public:
    DisjointSets(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) {
            return parent[x];
        }
        //path compression
        return parent[x] = find(parent[x]);
    }
    //by rank
    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) return;

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};
int mst(int n){
    vector<pair<int, pair<int,int>>> edges;
    vector<pair<pair<int,int>,int>> mstree;
    for(int i=0+k;i<n+k;i++){
        for(auto vertex:g[i]){
            int node =vertex.first;
            int weight=vertex.second;
            edges.push_back({weight,{node,i}});
        }
    }
    //n+e
    DisjointSets sets(n);
    sort(edges.begin(),edges.end());
    //eloge
    int total_weight=0;
    for(auto it : edges){
        int wt = it.first;
        int n1 = it.second.first;
        int n2 = it.second.second;

        if(sets.find(n1)!=sets.find(n2)){
            total_weight+=wt;
            sets.unite(n1,n2);
            mstree.push_back({{n1,n2},wt});
        }
        //elogv
    }
    cout<<"nodes"<<"\t"<<"weight"<<endl;
        for(auto it : mstree){
            cout<<it.first.first<<"-"<<it.first.second<<" \t"<<it.second<<endl;
        }
    return total_weight;
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
    int ans=mst(n);
    cout<<"total weight "<<ans<<endl;
} 
/*
9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 6 1
7 8 7
2 8 2
8 6 6
2 3 7
2 5 4
5 6 2
3 5 14
3 4 9
5 4 10
*/