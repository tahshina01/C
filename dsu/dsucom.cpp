#include <iostream>
#include <vector>

using namespace std;

class DisjointSets {
private:
    vector<int> parent, rank;

public:
    DisjointSets(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) {
            return parent[x];
        }
        //path compression
        return parent[x] = find(parent[x]);
    }
    //by rank
    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) return;

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

int main() {
    DisjointSets uf(7);
    uf.unite(1, 2);
    uf.unite(2, 3);
    uf.unite(4, 5);
    uf.unite(6, 7);
    uf.unite(5, 6);

    if(uf.find(3)==uf.find(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<" not same"<<endl;
    }
    uf.unite(3, 7);

    if(uf.find(3)==uf.find(7)){
        cout<<"same"<<endl;
    }
    
    return 0;
}
