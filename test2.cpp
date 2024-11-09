#include <bits/stdc++.h>
using namespace std;

const int N =100005;
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t,a;
    cin >> t;
   int v[N];
    while (t--) {
        int n,k;
        cin>>n>>k;
        k--;
        int count=0;
        for(int i=0;i<n;i++){
            cin>>a;
            v[i]=a;
        }
        for(int i=0;i<k;i++){
            if(v[k]<v[i]){
                swap(v[k],v[i]);
                if(i!=0) count++;
                k=i;
                break;
            }
        }
        for(int i=k+1;i<n;i++){
            if(v[k]>v[i] ){
                count++;
         
            }
            else{ break; }
        }
        cout<<count<<endl;
    
    }
}
