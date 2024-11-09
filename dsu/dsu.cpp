#include <bits/stdc++.h>
using namespace std;



class DisjointSets {
private:
    vector<int> parent, rank;

public:
    DisjointSets(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            x= parent[x];
        }
        return x;
        
    }


    void unionSets(int x, int y) {
        int rootX = find(x);
        //cout<<" rooyu6tx "<<rootX<<" x "<<x<<endl;
        int rootY = find(y);
        //cout<<" parent "<<rootY<<" x "<<parent[rootX]<<endl;
        parent[rootX] = rootY;
        
    }
};

int main() {
    int n = 10;
    DisjointSets dsu(n);

    dsu.unionSets(0, 1);
    dsu.unionSets(1, 2);
    dsu.unionSets(1, 3);
    dsu.unionSets(4, 5);
    dsu.unionSets(4, 6);
    dsu.unionSets(6, 7);
   
    if(dsu.find(3)==dsu.find(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<" not same"<<endl;
    }
    dsu.unionSets(3, 7);

    if(dsu.find(3)==dsu.find(7)){
        cout<<"same"<<endl;
    }

    return 0;
}