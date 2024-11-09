#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+10;
int g[100][100];
int k=1;
bool vis[N];

void clr(int n,int k){
    for(int i=0+k;i<n+k;i++){
        vis[i]=false;
    }
    for(int i=0+k;i<n+k;i++){
        for(int j=0+k;j<n+k;j++){
            g[i][j]=0;
        }
    }

}
int start(int n){
    for(int i=0+k;i<n+k;i++){
        int deg=0;
        for(int j=0+k;j<n+k;j++){
            if(g[i][j]) deg++;
        }
        if(deg%2!=0){
            return i;
        }
    }
    return k;
}
bool bridge(int n1, int n2,int n){
   int deg = 0;
   for(int i =0+k; i<n+k; i++){
    if(g[n2][i])
    deg++;
    if(deg>1){
    return false;
    }
   }
      
   return true;
}
void path(int ini,int n,int m){
    for(int i=k;i<n+k;i++){
        if(g[ini][i]){
            if(m<=1 || !bridge(ini,i,n)){
                cout<<ini<<"-"<<i<<" ";
                g[ini][i]=g[i][ini]=0;
                m--;
                path(i,n,m);
            }
        }

    }

}
//step:1 connectctivity check
//->edged no. of components 1
//step 2: count odd degree nodes
//-> 0: euler graph
//-> 2: semi-eulerian graph
//-> >2: non-euler graph


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cout<<"here"<<endl;
    int n,m;
    cin>>n>>m;
    
    clr(n,k);//o(n)
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1][v2]=1;
        g[v2][v1]=1;
    }
    path(start(n),n,m);
    
   
    
} 
/*
5 10
2 2
2 1
2 5
5 4
4 4
4 2
4 1
1 4
1 3
3 4
*/