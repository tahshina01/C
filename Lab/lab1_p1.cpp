#include<bits/stdc++.h>
using namespace std;
// find the target
int a[100000];
int binary_search(int left,int right,int target){
   

    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==target) return mid;
        else if(a[mid]>=a[left]){
            if(a[mid] >= target && a[left] <= target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(a[mid] <= target && a[right] >= target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
 return -1;
}
int main(){
    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
int n,target;
cin>>n>>target;
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<binary_search(0,n-1,target)<<endl;

}
