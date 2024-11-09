#include<bits/stdc++.h>
using namespace std;
//find the minimum number
int a[100000];
int binary_search(int a[],int n){
    int left=0;
    int right=n-1;
    int minimum=a[0];
    if(a[right]>a[left]){
        return a[0];
    }
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]>minimum){
            left=mid+1;
        }
        else{
            right=mid;
            minimum=a[mid];
            if(a[mid]<a[mid-1]){
                return a[mid];
            }
            
        }
    }
 return minimum;
}
int main(){
    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
int n;

cin>>n;
for(int i=0;i<n;i++){

    cin>>a[i];
}
cout<<binary_search(a,n)<<endl;

}
