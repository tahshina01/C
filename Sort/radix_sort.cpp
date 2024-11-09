#include<bits/stdc++.h>
using namespace std;
int a[10000];
int get_max(int n){
    int max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

void counting_sort(int n, int exp){
    
    int max= get_max(n);
    int count[max+5],output[n];
    memset(count,0,sizeof(count));
    memset(output,0,sizeof(output));
    for(int i=0;i<n;i++){
        count[(a[i]/exp)%10]++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        a[i]=output[i];
    }
}
void radix_sort(int n){
    int max= get_max(n);
    for(int exp=1; max/exp>0; exp*=10){
        counting_sort(n,exp);
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
    radix_sort(n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }


}


