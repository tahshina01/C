#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector<vector<int>> dp(1005,vector<int>(1005,INT_MAX));
int arr[1005][1005];
int rock_climb(int n,int m){
    for(int i=1;i<=m;i++){
        dp[0][i]=0;
        dp[1][i]=arr[0][i-1];
        
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=INT_MAX;
        dp[i][m+1]=INT_MAX;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=arr[i-1][j-1]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
}
void print(int i,int j,int n, int m){
    if((i==0)||(j==0)||(j==m+1)) return;
    if((dp[i-1][j-1]<=dp[i-1][j]) &&(dp[i-1][j-1]<=dp[i-1][j+1])){
        print(i-1,j-1,n,m);
    }
    else if((dp[i-1][j]<=dp[i-1][j-1]) &&(dp[i-1][j]<=dp[i-1][j+1])){
        print(i-1,j,n,m);
    }
    else if((dp[i-1][j+1]<=dp[i-1][j-1]) &&(dp[i-1][j+1]<=dp[i-1][j])){
        print(i-1,j+1,n,m);
    }
    cout<<dp[i][j]<<endl;
    
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,p,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    rock_climb(n,m);
    int ans=INT_MAX,index;
    for(int i=1;i<=m;i++){
        if(ans>=dp[n][i]){
            ans=dp[n][i];
            index=i;
        }
    }
    print(n,index,n,m);
} 
