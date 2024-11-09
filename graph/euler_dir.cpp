#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;
vector<int> g[N];
int k=1;
int dir=1;
bool vis[N];
bool vis1[N];
int indeg[N];
int outdeg[N];
int inout=0;
int outin=0;
int startnode=k;
int endnode=k;
stack<int> epath;
void clr(int n,int k){
    for(int i=0+k;i<n+k;i++){
        g[i].clear();
        vis[i]=false;
        indeg[i]=0;
        outdeg[i]=0;
        outin=0;
        inout=0;
        vis1[i]=false;
    }
}
//step:1 connectctivity check
//->edged no. of components 1
//step 2: count odd degree nodes
//-> 0: euler graph
//-> 2: semi-eulerian graph
//-> >2: non-euler graph

void dfs(int vertex){
    //cout<<vertex<<endl;
    vis[vertex]=true;
    for(int child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}

bool connectivity(int n,int k){

    dfs(0+k);
    for(int i=0+k;i<n+k;i++){
        if(!vis[i]){
            if(g[i].size()>0) return false;
        }
    }
    return true;

}


int direuler(int n,int k){
    if(connectivity(n,k)==false) return -1;
    for(int i=0+k;i<n+k;i++){
        //cout<<"in "<<indeg[i]<<"out "<<outdeg[i]<<endl;
        if((indeg[i]-outdeg[i])==1){
            endnode=i;
            inout++;
            //cout<<"inout "<<i<<endl;
        }
        else if((outdeg[i]-indeg[i])==1){
            startnode=i;
            outin++;
            //cout<<"outin "<<i<<endl;
        }
        else if(abs(indeg[i]-outdeg[i]>1)){
            return -1;
        }
    }
    if(inout==0 && outin==0){
        return 0;
    }
    else if(inout==1 && outin==1){
        return 2;
    }
    else{
        return -1;
    }

}
void path(int vertex){
    //cout<<vertex<<endl;
    //vis1[vertex]=true;
   while(outdeg[vertex]!=0){
        int child=g[vertex][--outdeg[vertex]];
        //if(vis1[child]) continue;
        //cout<<"child "<<child<<"vertex "<<vertex<<endl;
        path(child);
    }
    if(!outdeg[vertex]) cout<<vertex<<endl;
}
void dirpath(int vertex){
    
    vis1[vertex]=true;
    for(int child:g[vertex]){
        if(vis1[child]) continue;
        dirpath(child);
    }
    cout<<vertex<<endl;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n,m;
    cin>>n>>m;
    clr(n,k);//o(n)
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        outdeg[v1]++;
        indeg[v2]++;
    }
    int ans=-1;

    ans=direuler(n,k);
    
    if(ans==0){
        cout<<"euler graph or euler circuit"<<endl;
    }
    else if(ans==2){
        cout<<"semi-eulerian graph or eular path"<<endl;
    }
    else{
        cout<<"non-eulerian graph"<<endl;
    }
    
    if(ans==0||ans==2){
        dirpath(startnode);
    }
    
} 
