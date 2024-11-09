#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
long long dp[100][10005];
int arr[N];
int wt[N];
//if value<=10^9
long long knapsack(int index, int weight){
    if(weight==0 || index<0) return 0;
    if(dp[index][weight]!=-1) return dp[index][weight];

    long long ans= knapsack(index-1,weight);
    if((weight-wt[index])>=0){
        ans=max(ans, knapsack(index-1,weight-wt[index])+arr[index]); 
    }
    return dp[index][weight]=ans;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    int n,weight;
    cin>>n>>weight;
    for(int i=0;i<n;i++){
        
       cin>>wt[i]>>arr[i];
    }
    cout<<knapsack(n-1,weight)<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=weight;j++){
            cout<<dp[i][j]<<" ";

        }
        cout<<endl;
    }
    
} 
