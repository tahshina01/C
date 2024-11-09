#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector<int> len(0,N);
vector<int> prev(0,N);


vector<int> arr(0,N);
int LIS(int ind,int prev_ind,int n,vector<vector<int>> &dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][prev_ind+1]!=-1){
        return dp[ind][prev_ind+1];
    }
    int take=0;
    if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
        take=1+LIS(ind+1,ind,n,dp);
    }
    int not_take=0+LIS(ind+1,prev_ind,n,dp);
    return dp[ind][prev_ind+1]=max(take,not_take);
        

}

int solve_tab(int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
             int take=0;
            if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
                take=1+dp[ind+1][ind+1];
            }
            int not_take=0+dp[ind+1][prev_ind+1];
            dp[ind][prev_ind+1]=max(take,not_take);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
    }
    
    return dp[0][0];
    
}
//optimized space
int solve_tab2(int n){
    vector<int> currrow(n+1,0);
    vector<int> nextrow(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
             int take=0;
            if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
                take=1+nextrow[ind+1];
            }
            int not_take=0+nextrow[prev_ind+1];
            currrow[prev_ind+1]=max(take,not_take);
        }
        nextrow=currrow;
    }
    return nextrow[0];
}
int solveoptimal(int n){
    if(n==0){
        return 0;
    }
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int ind=1;ind<n;ind++){
        if(arr[ind]>ans.back()){
            ans.push_back(arr[ind]);
        }
        else{
            //index of immediate small number
            int i=lower_bound(ans.begin(),ans.end(),arr[ind])-ans.begin();
            ans[i]=arr[ind];
        }
    }
    return ans.size();
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n;
     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    for(int i=0;i<n;i++){
        cin>>m;
        arr.push_back(m);
    }
    //cout<<LIS(0,-1,n,dp)<<endl;
    cout<<solve_tab(n)<<endl;
    //cout<<solveoptimal(n)<<endl;

} 
