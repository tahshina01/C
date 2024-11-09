#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 500;

class Graph {
private:
    int V; 
    int adjMatrix[MAX_SIZE][MAX_SIZE]; 

public:
    Graph(int V) {
        this->V = V;

       
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }


    void printAdjMatrix() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void BFS(int s) {
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++) {
            visited[i] = false;
        }

        queue <int> q;
        visited[s] = true;
        q.push(s);

        while(!q.empty()) {
            s = q.front();
            cout << s << " ";
            q.pop();

            for(int p = 0; p <V; ++p) {
                if(!visited[p]) {
                    visited[p] = true;
                    q.push(p);
                }
            }
        }
    }

    void dfs(int start, bool visited[]) {
    visited[start] = true;
    cout << start << " ";

    for (int i = 0; i < V; i++) {
        if (adjMatrix[start][i] == 1 && !visited[i]) {
            dfs(i, visited);
        }
    }
}

void DFS(int start) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    dfs(start, visited);

    delete[] visited;
}


     
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printAdjMatrix();
    cout << "BFS starting from vertex 2: ";
    g.BFS(2);
    cout << "DFS starting from vertex 2: ";
    g.DFS(2);


    return 0;
}
