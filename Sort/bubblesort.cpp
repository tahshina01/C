#include<bits/stdc++.h>
using namespace std;
int a[10000];
void bubble_sort(int n){
    
    if(n==1) return;
        bool swapped = false;
            for(int j=0;j<n-1;j++){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    swapped=true;
                }
            }
        
        if(!swapped) return;

        bubble_sort(n-1);
}

int main(){

    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubble_sort(n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


}


