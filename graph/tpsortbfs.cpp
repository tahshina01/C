#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector <int> g[N];
bool vis[N];
vector<int> tp;

vector<int> indeg(N,0);
void tpsort(int n){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        tp.push_back(t);
        for(auto it:g[t]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
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
        indeg[v2]++;


    }
    tpsort(n);
    for(int i:tp){
        cout<<i<<endl;
    }
    
} 
