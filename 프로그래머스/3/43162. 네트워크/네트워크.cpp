#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void DFS(int i, int n, vector<vector<int>> &computers, vector<int> &visited)
{
    for(int j=0; j<n; j++)
    {
        if(visited[j] == 0 && i != j && computers[i][j] == 1)
        {
            visited[j] = 1;
            DFS(j, n, computers, visited);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int network = 0;
    vector<int> visited(n, 0);
    
    for(int i=0; i<n; i++)
    {
        if(visited[i] == 1) continue;
        
        network++;
        visited[i] = 1;
        DFS(i, n, computers, visited);
    }
    
    return network;
}