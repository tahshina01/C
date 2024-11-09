
#include <bits/stdc++.h>
using namespace std;

#define V 6

bool DFS_path(int source, int sink, int residual[V + 2][V + 2], int parent[]) {
    bool visited[V + 2];
    memset(visited, 0, sizeof(visited));

    stack<int> s;
    parent[source] = -1;
    s.push(source);
    visited[source] = true;

    while (!s.empty()) {
        int start = s.top();
        s.pop();

        for (int v = 0; v < V + 2; v++) {
            if (residual[start][v] > 0 && !visited[v]) {
                if (v == sink) {
                    parent[v] = start;
                    return true;
                }
                s.push(v);
                parent[v] = start;
                visited[v] = true;
            }
        }
    }

    return false;
}

bool BFS_path( int source,int sink,int residul[V+2][V+2], int parent[])
{
	bool visited[V+2];
	memset(visited, 0, sizeof(visited));

	queue<int> q;
	parent[source]= -1;
	q.push(source);
	visited[source]= true;
	while (!q.empty()) {
		int start= q.front();
		q.pop();

		for (int v=0; v<V+2; v++) {
			if ( residul[start][v]>0 && visited[v]== false) {
				if (v== sink) {
					parent[v]= start;
					return true;
				}
				q.push(v);
				parent[v]= start;
				visited[v]= true;
			}
		}
	}

	return false;
}

int Ford_fulkerson( vector<int> sources, vector<int> sinks,int graph[V][V])
{
	int inf=1e9;
	int u, v;
	int maximum= 0; 
	int residul[V+2][V+2]; 
	for (u=0; u<V; u++){
		for (v=0; v<V; v++){
			residul[u+1][v+1]= graph[u][v];
		}	
	}
	for(int p=0;p<V+2;p++){
		residul[0][p]=0;
		residul[p][0]=0;
		residul[p][V+1]=0;
		residul[v+1][p]=0;
	}
	for(int p=0;p<sources.size();p++){
		residul[0][sources[p]+1]=inf;
	}
	for(int p=0;p<sinks.size();p++){
		residul[sinks[p]][V+1]=inf;
	}
	// for (u=0; u<V+2; u++){
	// 	for (v=0; v<V+2; v++){
	// 		cout<<residul[u][v]<<" ";
	// 	}	
	// 	cout<<endl;
	// }
		
	int parent[V+2]; 

	
	while (BFS_path( 0,V+1,residul,parent)) {
		
		int bottleneck = INT_MAX;
		for (v=V+1; v!= 0; v=parent[v]) {
			u= parent[v];
			bottleneck = min(bottleneck, residul[u][v]);	
		}
		for (v=V+1; v!= 0; v=parent[v]) {
			u= parent[v];
			residul[u][v]-=bottleneck;
			residul[v][u]+=bottleneck;
		}
		maximum+=bottleneck;
	}
	


	return maximum;
}

int main()
{
	int inf=1e9;
	vector<int> sources={0,1};
	vector<int> sinks={5,6};
	int flow[V][V]
		= { {0,0,13,14,0,0},
		{0,0,0,15,0,0},{0,0,0,0,14,12},
		{0,0,12,0,14,13},{0,0,0,0,0,0},{0,0,0,0,0,0}};
		// ={ {0,inf,inf,0,0,0,0,0},{0,0,0,3,4,0,0,0},
		// {0,0,0,0,5,0,0,0},{0,0,0,0,0,4,2,0},
		// {0,0,0,2,0,4,3,0},{0,0,0,0,0,0,0,inf},{0,0,0,0,0,0,0,inf},{0,0,0,0,0,0,0,0}};
	cout<< "maximum traffic flow: "<<Ford_fulkerson(sources, sinks,flow);

	return 0;
}
