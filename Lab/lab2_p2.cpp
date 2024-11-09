#include<bits/stdc++.h>
using namespace std;
int a[100000],a1[100000];
int maximum=0;
// relative sort
void countSort(int a[], int a1[], int n, int m,int maximum)
{
    int output[n];
 
    int count[maximum + 1], i;
    memset(count, 0, sizeof(count) );

    for (i = 0; i<n; ++i){

        ++count[a[i]];
    }
    
    int k=0;

    for (i = 0; k<m;){

           while(count[a1[k]]){
            output[i] = a1[k];
            --count[a1[k]];
            i++;
        }
        k++;
    }

    for(int k=0;k<=maximum;k++){

        while(count[k]){
    
            output[i]=k;
            --count[k];
            i++;
    
        }
    }

    for (int j = 0; j<i; ++j){
    
        a[j] = output[j];
    
    }
    
}
int main(){

    freopen("lab2_p2.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
    
        cin>>a[i];
    
        if(a[i]>maximum){
    
            maximum=a[i];
    
        }
    
    }
    for(int i=0;i<n;i++){
    
        cin>>a1[i];
    
    }

    countSort(a,a1,n,m,maximum);
    
    for(int i=0;i<n;i++){
    
        cout<<a[i]<<" ";
    
    }

}


