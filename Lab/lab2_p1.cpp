#include <bits/stdc++.h>
using namespace std;
int arr[100000];

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i=i+2){
            int min_index=i;
        for(int j=i+2;j<n;j+=2){
            if(arr[j]<arr[min_index]){
                    min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
    for(int i=1;i<n-1;i=i+2){
            int min_index=i;
        for(int j=i+2;j<n;j+=2){
            if(arr[j]>arr[min_index]){
                    min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}


int main(){
    freopen("inputshort.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);

    int n=8;

    for(int i=0;i<n;i++){

        cin>>arr[i];
    }
    selection_sort(arr,n);

    for(int i=0;i<n;i++){

        cout<<arr[i]<<" ";
    }
}