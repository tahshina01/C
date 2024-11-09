#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;
vector<pair<int,pair<int,int>>> g;
int k=0;
vector<int> dis(N);
void sp(int source,int n){
    dis[source]=0;
    for(int i=0;i<n-1;i++){
        for(auto node:g){
            int start=node.first;
            int end=node.second.first;
            int weight=node.second.second;
            if(dis[start]!=INT_MAX &&  (dis[start]+weight<dis[end])){
                //cout<<dis[end]<<" a "<<end<<" "<<dis[start]+weight<<endl;
                dis[end]=dis[start]+weight;
            }
        }
    }
    for(auto node:g){
        int start=node.first;
            int end=node.second.first;
            int weight=node.second.second;
            if(dis[start]!=INT_MAX  && (dis[start]+weight<dis[end])){
                cout<<"nc"<<endl;
            }
    }
    
}
void clr(int n){
    for(int i=k;i<n+k;i++){
       dis[i]=INT_MAX;
        g.clear();
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
        g.push_back({v1,{v2,w}});
        g.push_back({v2,{v1,w}});
    }
    
    int source;
    cin>>source;
    sp(source,n);
    //E*logV
    for(int i=k;i<n+k;i++){
        cout<<i<<" "<<dis[i]<<endl;
    }
} 
/*
6 8
0 2 4
0 1 4
1 2 2
2 4 1
2 5 6
2 3 3
3 5 2
4 5 3
2
// node node weight
*/

/*
priority queue
weight node node
*/
/*6 7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3
0*/