#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
			//현재 위치와 현재 걸음 수 기록을 담는 queue
    queue<pair<pair<int, int>, int>> q;
    
    //현재 타일에 방문한 적이 있는지 확인하는 vector
    //만약 두번째로 방문하는 경우의 수가 있다면 해당 경우의 수는 전에 방문한 경우의 수보다
    //스텝이 많고 앞으로 갈 방향 같기 때문에 더이상 확인하지 않는다.
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    //첫 플레이어 위치인 0,0은 방문
    visited[0][0] = true;
    
    //좌,우,상,하 로 이동 시 변화하는 좌표 저장
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

		//첫 경우 q에 삽입
    q.push(make_pair(make_pair(0,0), 1));
    
    while(!q.empty())
    {
		    //현재 확인할 경우 꺼내고 삭제하기
        pair<pair<int, int>, int> currentPos = q.front();
        q.pop();
        
        //현재 좌표 보기 쉽게 할당
        int x = currentPos.first.first;
        int y = currentPos.first.second;
        
        //현재 걸음 수 보기 쉽게 할당
        int steps = currentPos.second;
        
        //현재 위치가 목적지 일때 현재 걸음 수 반환
        if(x == maps[0].size() - 1 && y == maps.size() - 1)
            return steps;
        
        //상하좌우로 움직인다.
        for(pair<int, int> p : direction)
        {
            int nextX = x + p.first;
            int nextY = y + p.second;
            
            //움직였는데 범위를 벗어나지 않고 방문하지 않은 타일이며 벽이 아닐 시
            if(nextX >= 0 && nextX < maps[0].size() && nextY >= 0 && nextY < maps.size() && visited[nextY][nextX] != true && maps[nextY][nextX] != 0)
            {
		            //현재 타일에 방문했다고 남기고
                visited[nextY][nextX] = true;
                //현재 위치로 이동한 후 q에 삽입
                q.push(make_pair(make_pair(nextX, nextY), steps + 1));
            }
        }
    }
    
    return -1;
}