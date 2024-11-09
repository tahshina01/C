#include <bits/stdc++.h>
using namespace std;
const int N =100005;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,a,b,avg,total,max=0,least;
    vector<int> money(N,0);
    cin>>t;
    while(t--){
        max=0;
        total=0,least=0;
        cin>>a;
        for(int i=0;i<a;i++){
            cin>>b;
            money.push_back(b);
            total+=b;
            if(b>max) max=b;
        }
        for(auto a:money){
            cout<<a<<endl;
        }
        sort(money.begin(),money.end());
        int j=a/2;
        least=money[j];
        cout<<"least "<<least<<endl;
        least=least*2*a;
        least++;
        if(least<=max){
            cout<<"-1"<<endl;
        }
        else{
            least=least-max;
            cout<<least<<endl;
        }
        

    }
    return 0;
}