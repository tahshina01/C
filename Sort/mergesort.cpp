#include<bits/stdc++.h>
using namespace std;
int a[10000];
void merge(int left, int mid, int right){
    int l1=mid-left+1;
    int l2=right-mid;
    int arr1[l1],arr2[l2];
    for(int i=0;i<l1;i++){
        arr1[i]=a[left+i];
    }
    for(int i=0;i<l2;i++){
        arr2[i]=a[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<l1 && j<l2){
        if(arr1[i]<=arr2[j]){
            a[k]=arr1[i];
            k++;
            i++;
        }
        else{
            a[k]=arr2[j];
            k++;
            j++;
        }
    }
        while(i<l1){
            a[k]=arr1[i];
            k++;
            i++;
        }
        while(j<l2){
            a[k]=arr2[j];
            k++;
            j++;
        }
    

}
void merge_sort(int left, int right){

    if(left<right){
        int mid=(left+right)/2;
        merge_sort(left,mid);
        merge_sort(mid+1,right);
        merge(left,mid,right);
    
    }
    
}

int main(){

    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int left=0;
    int right=n-1;
    merge_sort(left,right);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }


}


