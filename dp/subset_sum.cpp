#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
long long dp[100][20005];
int arr[N];
int wt[N];
//if wt<=10^9
bool subset_sum(int i, int sum){
    if(sum==0 ) return true;
    if(i<0) return false;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int subset= subset_sum(i-1,sum);
    if(sum-arr[i]>=0){
        subset|=subset_sum(i-1,sum-arr[i]);
    }
    return dp[i][sum]=subset;

}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    int n,sum;
    cin>>n>>sum;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<subset_sum(n,sum)<<endl;
} 
