#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector<int> len(0,N);
vector<pair<int, int>> arr;


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
    int n,m,i;
    cin>>n;
     
    for(int i=0;i<n;i++){
        cin>>m>>i;
        arr.push_back(m,i);
    }
    //cout<<LIS(0,-1,n,dp)<<endl;
    //cout<<solve_tab2(n)<<endl;
    cout<<solveoptimal(n)<<endl;

    
} 
