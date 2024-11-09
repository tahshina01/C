#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector<int> dp(20,-1);
vector<int> arr(0,N);
vector<int> taken;
int LIS(int j,int k){
    int ans=1;
    if(dp[j]!=-1) {

        return dp[j];
    }

    for(int i=0;i<j;i++){

        if((arr[j]-arr[i])>=k){
            if(ans<=LIS(i,k)+1){
                ans=LIS(i,k)+1;
                taken.push_back(arr[i]);

            }
            
        }
        
    }
    return dp[j]=ans;
}

int solveoptimal(int n,int k){
    if(n==0){
        return 0;
    }
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int ind=1;ind<n;ind++){
        if((arr[ind]-ans.back())>=k){
            ans.push_back(arr[ind]);
            cout<<ans.back()<<endl;
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
    freopen("p2.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n,k,m,max=0;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>m;
        arr.push_back(m);
    }
    int ans=LIS(n-1,k);
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
       
        cout<<dp[i]<<" ";
        
    }
    cout<<endl;
    for(int i=0;i<n;){
        if( i>0 &&(dp[i]==dp[i-1]||dp[i]<dp[i-1] ||dp[i]<=max )){
            i++;
            continue;
        }
        else{
            if(dp[i]>max){
                max=dp[i];
            }
            cout<<arr[i]<<" ";
            i++;
        }
    }
    cout<<endl;

    cout<<solveoptimal(n,k)<<endl;
} 


