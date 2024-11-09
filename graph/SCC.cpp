#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector <int> g[N];
vector <int> Tg[N];
vector <int> c;
vector<vector<int>> cc;
bool vis[N];
void dfs(int vertex,stack<int> &s){
    
    vis[vertex]=true;
    for(int child:g[vertex]){
        if(vis[child]) continue;
        dfs(child,s);
        //cout<<child<<endl;
    }
    s.push(vertex);
}
void revdfs(int vertex){
    c.push_back(vertex);
    vis[vertex]=true;
    for(int child:Tg[vertex]){
        if(vis[child]) continue;
        revdfs(child);
       // cout<<"child"<<child<<endl;
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
    }
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,s);
        }
    }
//transpose
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(int a:g[i] ){
            Tg[a].push_back(i);
        }
        
    }
    int count=0;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        c.clear();
        if(!vis[top]){
           // cout<<top<<endl;
            count++;
            //cout<<"count "<<count<<endl;
            //cout<<"top "<<top<<endl;
            revdfs(top);
            cc.push_back(c);
        }
        
    }
    for(auto i:cc){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<count<<endl;
    
} 
/*
1 2
8 8
2 6
5 6
3 7
5 1
2 5
2 3
3 4
7 6
7 8
4 3
4 8
6 7
*/