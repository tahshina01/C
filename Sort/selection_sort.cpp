#include<bits/stdc++.h>
using namespace std;
int a[10000];
void selection_sort(int a[], int n){
    if(n==1) return ;
    int min=0;
    for(int i=1;i<n;i++){
        if(a[min]>a[i]){
            min=i;
        }
    }
    swap(a[0],a[min]);
    selection_sort(a+1,n-1);
    
}

int main(){

    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selection_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }


}


