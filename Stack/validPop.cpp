#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int>& pushed, vector<int>& popped) {
        int len=popped.size(),i=0,j=0;
    for(auto &n : pushed){
        cout<<i<<" "<<n<<endl;
        pushed[i++]=n;
        while(i>0 && j<len && pushed[i-1]==popped[j]){
            cout<<i-1<<" " <<pushed[i-1]<<" "<<j<<" "<<popped[j]<<endl;
            i--;j++;
        }
    } return j==len && i==0;
}

int main() {
    vector<int> pushed{1,2,3,4,5};
    vector<int> popped{4,5,3,2,1};
    cout << valid(pushed,popped)<<endl;
    return 0;
}