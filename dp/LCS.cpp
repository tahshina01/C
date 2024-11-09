#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
int dp[1005][1005];
vector<int> arr(0,N);
vector<char> taken(10);
int lcs(int i, int j,string &a,string &b){
    if(i<0||j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=lcs(i-1,j,a,b);
    ans=max(ans,lcs(i,j-1,a,b));
    int p=lcs(i-1,j-1,a,b)+(a[i]==b[j]);
    if(ans<p){
        ans=p;
        taken.push_back(i);

    }
    //ans=max(ans,lcs(i-1,j-1,a,b)+(a[i]==b[j]));

    return dp[i][j]= ans;

}
//o(n^2)

int main(){
    freopen("P1.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));

    cout<<lcs(a.size()-1,b.size()-1,a,b)<<endl;

    for(int i=0;i<a.size();i++){

        for(int j=0;j<=b.size()-1;j++){

            cout<<dp[i][j]<<" ";

        }

        cout<<endl;
    }
    for(int i=0;i<taken.size();i++){
        cout<<a[taken[i]]<<" ";
    }
} 
