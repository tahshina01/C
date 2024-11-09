#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector <int> g[N];
bool vis[N];
vector<int> tp;
vector<int> a;
//valid topological sorts in a graph

void display(vector<int> a, int n){
    for(int i=0;i<n;i++) cout << a[i];
    cout << endl;
    
}
bool valid_tp(vector<int> a,vector<int> indeg, int n){
    for(int i=0;i<n;i++){
        //cout<<" i "<<a[i]<<" indeg "<<indeg[a[i]]<<endl;

        if(indeg[a[i]]==0){
            
            for(auto it:g[a[i]]){
                //cout<<" i "<<it<<" it "<<indeg[it]<<endl;
             
             indeg[it]--;
                
            }
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int> indeg(N,0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        indeg[v2]++;


    }
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    int count=0;
    do{
        
        if(valid_tp(a,indeg,n)==true){
            count++;
            //display(a, n);
        }
    
        
    
    }while(next_permutation(a.begin(), a.end())); 

    cout<<"no. of valid topological sort: "<< count<<endl;
} 