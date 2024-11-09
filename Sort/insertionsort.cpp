#include<bits/stdc++.h>
using namespace std;
int a[10000];
void insertion_sort(int a[], int n){
    if(n==1) return;
    insertion_sort(a,n-1);
        int j=n-1;
        while(j>0 && a[j]<a[j-1]){
            swap(a[j],a[j-1]);
            j--;
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
    insertion_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }


}


