#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> meeting;
vector<pair<int,int>> held;
vector<int> start;
vector<int> end;
bool compare(pair<int,int> a,pair<int,int> b ){
    return a.second<b.second;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int count =0,end=0;
    
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        meeting.push_back({a,b});
    }
    // for(int i=0;i<n;i++){
    //     int a;
    //     cin>>a;
    //     start.push_back(a);
    // }
    // for(int i=0;i<n;i++){
    //     int a;
    //     cin>>a;
    //     end.push_back(a);
    // }
    // for(int i=0;i<n;i++){
    //     meeting.push_back({start[i],end[i]});
    // }
    sort(meeting.begin(),meeting.end(),compare);
    for(int i=0;i<n;i++){

        if(meeting[i].first>end){
            count++;
            held.push_back({meeting[i]});
            end=meeting[i].second;
        }

    }
    cout<<count<<endl;
    for(int i=0;i<held.size();i++){
        cout<<held[i].first<<" "<<held[i].second<<endl;
    }
    

}