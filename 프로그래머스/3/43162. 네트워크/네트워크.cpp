#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


int solution(int n, vector<vector<int>> computers) {
    int answer{0};
    map<int,vector<int>> m;
    vector<bool> visit(n,false);

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(computers[i][j] != 1) continue;
            m[i].push_back(j);
        }
    }

    for(int k=0;k<n;++k){ //모든 노드를 시작지점으로.
        if(visit[k]) continue;

        queue<int> q;
        visit[k] = true;
        ++answer;
        q.push(k);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i=0;i<m[cur].size();++i){
                if(visit[m[cur][i]] != false) continue;
                visit[m[cur][i]] = true; 
                q.push(m[cur][i]);
            }

        }
    }


    return answer;
}