#include <string>
#include <vector>
#define MAX 8

using namespace std;
// dfs 사용
int answer = 0;
bool visited[MAX] = {false};

void dfs(int cnt, int k, vector<vector<int>> &dungeons)
{
    if(cnt > answer) answer = cnt;
    
    for(int i=0; i<dungeons.size(); i++)
    {
        if(visited[i] == false && dungeons[i][0] <= k)
        {
            visited[i] = true; // 방문기록
            dfs(cnt+1, k-dungeons[i][1], dungeons); // 다음 탐색
            visited[i] = false; // 방금 탐색한 곳은 for문에 의한 재탐색을 위해 다시 미방문 기록
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return answer;
}