#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
long long dp[100][10005];
int arr[N];
int wt[N];
//if wt<=10^9
long long knapsack(int index, int value){
    if(value==0) return 0;
    if(index<0) return 2e15;

    if(dp[index][value]!=-1) return dp[index][value];

    long long ans= knapsack(index-1,value);
    if((value-arr[index])>=0){
        ans=min(ans, knapsack(index-1,value-arr[index])+wt[index]); 
    }
    return dp[index][value]=ans;
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

    
    //warning
    int max=1e5;
    for(int i=max;i>=0;i--){
        if(knapsack(n-1,i)<=weight){
            cout<<i<<endl;
            break;
        }
    }
    
} 
