#include <bits/stdc++.h>
using namespace std;

#define applicant 6
#define jobs 6

int assigned[jobs];

bool match(bool bpGraph[applicant][jobs], int u, bool visited[]){
	for (int v=0;v<jobs;v++){
		if (!visited[v] && bpGraph[u][v]){
			visited[v]= true; 
			if (assigned[v]<0||match(bpGraph, assigned[v],visited))
			{
				assigned[v]=u;
				return true;
			}
		}
	}
	return false;
}


int maxBPM(bool graph[applicant][jobs]){
	int result = 0; 
    
	for (int i= 0; i<applicant; i++)
	{
		bool visited[jobs];
		memset(visited, 0, sizeof(visited));

		if (match(graph, i, visited)){
            result++;
        }
		
	}
    for(int i=0;i<jobs;i++){
        cout<<i<<" assigned to:" <<assigned[i]<<endl;
    }
	return result;
    
}

int main(){
    memset(assigned, -1, sizeof(assigned));

	bool graph[applicant][jobs] = 
    {{0, 1, 1, 0, 0, 0},
	{1, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1}};

	cout <<  maxBPM(graph);

	return 0;
}
