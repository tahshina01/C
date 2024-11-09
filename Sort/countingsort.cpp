#include<bits/stdc++.h>
using namespace std;
int a[10000];

void counting_sort(int n){
    int max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    
    int count[max+5],output[n];
    memset(count,0,sizeof(count));
    memset(output,0,sizeof(output));
    for(int i=0;i<n;i++){
        count[a[i]]++;
        //cout<<" here 1 "<<count[a[i]]<<" "<<a[i]<<endl;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
       // cout<<" here 2 "<<count[i]<<endl;
    }
    for(int i=n-1;i>=0;i--){
        
        output[count[a[i]]-1]=a[i];
        //cout<<" here 3 "<<b[count[a[i]]-1]<<" "<<count[a[i]]-1<<endl;
        count[a[i]]--;
    }
    for(int i=0;i<n;i++){
        a[i]=output[i];
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
    counting_sort(n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }


}


