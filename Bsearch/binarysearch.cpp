#include<bits/stdc++.h>
using namespace std;
int a[10000];
int binary_search(int left, int right, int target){
    
        if(left<=right)
        {
            int mid=(left+right)/2;
            cout<<mid<<" here "<<endl;
            if(a[mid]==target){
                cout<<" returned "<<mid<<endl;
                return mid;
                cout<<" ha "<<endl;
                
            }
            else if(target<a[mid]){
                return binary_search(left,mid-1,target);
            }
            else{
                return binary_search(mid+1,right,target);
            }
        }
        

    return -1;
}
int main(){

    freopen("lab2_p2.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    int n,target;
    cin>>n>>target;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b= binary_search(0,n-1,target);
    cout<<b<<endl;


}


