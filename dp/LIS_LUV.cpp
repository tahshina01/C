#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector<int> dp(N,-1);
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
                taken.push_back(arr[j]);

            }
            
        }
        
    }
    return dp[j]=ans;
}


int main(){
    freopen("p2.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,m;
    cin>>n>>k;
     
    for(int i=0;i<n;i++){
        cin>>m;
        arr.push_back(m);
    }

    cout<<LIS(n-1,k)<<endl;
    for(int i=0;i<dp.size()-1;i++){
        cout<<dp[i]<<endl;
    }
    
} 

/*
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to find longest subsequence
// having absolute difference between
// maximum and minimum element K
void longestSubsequenceLength(int arr[],
                              int N, int K)
{
    // Stores the frequency of each
    // array element
    unordered_map<int, int> um;
 
    // Traverse the array arr[]
    for (int i = 0; i < N; i++)
 
        // Increment um[arr[i]] by 1
        um[arr[i]]++;
 
    // Store the required answer
    int ans = 0;
 
    // Traverse the hashmap
    for (auto it : um) {
 
        // Check if it.first + K
        // exists in the hashmap
        if (um.find(it.first + K)
            != um.end()) {
 
            // Update the answer
            ans = max(ans,
                      it.second
                          + um[it.first + K]);
        }
    }
 
    // Print the result
    cout << ans;
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 3, 2, 2, 5, 2, 3, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 1;
 
    longestSubsequenceLength(arr, N, K);
 
    return 0;
}
*/