#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int dp[N];
int r[N];

int brute_force(int price[], int idx){
    if(idx == 0){
        return 0;
    }

    int res = -1;

    for(int i=1; i <=idx; i++){
        int temp = price[i-1] + brute_force(price,idx -i);
        res = max (res, temp);
    }
    return res;
}

int bottom_up(int price[], int idx){
    r[0]=0;

    for(int j=1;j<=idx;j++){
        int q=-1;
        for(int i=1; i <=j; i++){

         r[j] = price[i-1] + r[j-i];
         cout<<r[j]<<" ";
        }
        cout<<endl;
    }

    
    return r[idx];
}
int memoization(int price[], int idx){
    if(idx == 0){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }

    int res = -1;

    for(int i=1; i <=idx; i++){
        int temp = price[i-1] + brute_force(price,idx -i);
        res = max (res, temp);
    }
    return dp[idx] = res;
}
int rod_cut(int len, int p[]){
    if(len==0) {return 0;}
    if(dp[len]!=-1) {return dp[len];}
    int ans=0;
    for(int i=1;i<=len;i++){
        if(len-i>=0){
            ans=max(ans,rod_cut(len-i,p)+p[i-1]);
        }
    }
   return dp[len]=ans;

}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    for(int i=0; i<N; i++){
        dp[i] = -1;
    }
    int q;
    int prices[] = {1,5,8,9,10,17,17,20};
    int size = sizeof(prices)/sizeof(prices[0]);
    
    cout<<rod_cut(size,prices)<<endl;
    
    // double s1 = clock();
    // cout << brute_force(prices,size) << endl;
    // double sto1 = clock();
    
    // auto d1 = (sto1 - s1);
 
    // cout << "brute: time "<< d1 << " microseconds" << endl;


    // double st = clock();
    // cout << memoization(prices,size) << endl;
    // double sto = clock();
    
    // auto d2 = (sto - st);
 
    // cout << " memo: time "<< d2 << " microseconds" << endl;


    // double st2 = clock();
    // cout << bottom_up(prices,5) << endl;
    // double sto2 = clock();
    
    // auto d3 = (sto2 - st2);
 
    // cout << "bottomup: time"<< d3 << " microseconds" << endl;


}