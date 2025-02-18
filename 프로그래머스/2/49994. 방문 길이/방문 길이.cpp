#include <string>
#include <unordered_set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    unordered_set<string> visited;
    // 1. 처음부터 갈 때, 반대 방향도 저장해두기
    // 2. 좌표가 범위 넘어가면 다음 dirs로 넘어감
    int x = 0, y = 0;
    for(auto d: dirs)
    {
        int prev_x = x, prev_y = y;
        if(d == 'U')
        {
            if(y+1 > 5) continue; 
            y += 1;
        }
        else if(d == 'D')
        {
            if(y-1 < -5) continue;
            y -= 1;
        }
        else if(d == 'R')
        {
            if(x+1 > 5) continue;
            x += 1;
        }
        else if(d == 'L')
        {
            if(x-1 < -5) continue;
            x -= 1;
        }
        
        string go = to_string(prev_x) + to_string(prev_y) + to_string(x) + to_string(y);
        string back = to_string(x) + to_string(y) + to_string(prev_x) + to_string(prev_y);
        
        if(visited.find(go) == visited.end()) // 없다면
        {
            visited.insert(go);
            visited.insert(back);
            answer++;
        }
    }
    
    return answer;
}