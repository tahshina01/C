#include<bits/stdc++.h>
using namespace std;
const int N= 2000;
int h=0;
vector<vector<int>> g(N, vector<int>(N, -1));
vector<vector<int>> p(N, vector<int>(N, -1));
void floydwarshall(int n){
    for(int i=h;i<n+h;i++){
        for(int j=h;j<n+h;j++){
            if(g[i][j]==-1){
                g[i][j]=INT_MAX;
            }
            if(i==j) g[i][j]=0;
        }
    }

    for(int k=h;k<n+h;k++){
        for(int i=h;i<n+h;i++){
            for(int j=h;j<n+h;j++){
                if(g[i][k]!=INT_MAX && g[k][j]!=INT_MAX){
                    if((g[i][k]+g[k][j])<g[i][j]){
                        g[i][j]=g[i][k]+g[k][j];
                        p[i][j]=k;
                    }
                
                }
            }

        }
    }
    for(int i=h;i<n+h;i++){
        if(g[i][i]<0){
            cout<<"neg cycle"<<endl;
        }
    }
    for(int i=h;i<n+h;i++){
        for(int j=h;j<n+h;j++){
            if(g[i][j]==INT_MAX){
                g[i][j]=-1;
            }
        }
    }
    
}
void clr(int n){
    for(int i=h;i<n+h;i++){
        for(int j=h;j<n+h;j++){
            g[i][j]=-1;
        }
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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n,m;
    cin>>n>>m;
    clr(n);
    for(int i=0;i<m;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        g[v1][v2]=w;
        p[v1][v2]=v1;
        //g[v2][v1]=w;
    }
    
    floydwarshall(n);
    cout<<"ans"<<endl;
    for(int i=h;i<n+h;i++){
        for(int j=h;j<n+h;j++){
            cout<< g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"predecessor"<<endl;
    for(int i=h;i<n+h;i++){
        for(int j=h;j<n+h;j++){
            cout<< p[i][j]<<" ";
        }
        cout<<endl;
    }
    int start,term;
    cin>>start>>term;
    printpath(start,term);
    cout<<term<<endl;
} 
/*
0 1 4 7 8 
5 0 3 6 7 
2 3 0 3 4 
-1 -1 -1 0 1 
-1 -1 -1 -1 0 

2
// node node weight
*/
/*
priority queue
weight node node
*/
/*
5 9
0 1 3
0 2 8
0 4 -4
1 4 7
1 3 1
2 1 4
3 0 2
3 2 -5
4 3 6
*/