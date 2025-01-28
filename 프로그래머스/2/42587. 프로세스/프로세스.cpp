#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // pop_front로 하나씩 빼기 , 우선순위 비교, 만약 큰 게 있으면 push_back
    // 꺼낸 게 가장 큰 거면 실행 (answer += 1), 반복
    // 하나씩 뺄 때마다 location 번호 -1, 0이 되는 순간 실행되면 그 때 answer값 반환
    // 다시 뒤로 들어가면 현재 남은 스택 갯수 세서 location에 번호 다시 부여
    while(!priorities.empty())
    {
        int tmp = priorities.front();
        bool nxt = false;
        priorities.erase(priorities.begin(), priorities.begin()+1); // 맨 앞꺼 빼두기
        location--; // 알고 싶은 것의 위치 변함
        
        for(int j=0; j<priorities.size(); j++)
        {
            if(priorities[j] > tmp) nxt = true; // 우선순위 큰 게 있으면 다음 꺼 꺼내기
        }
        if(nxt) // 우선순위 큰 게 있어서 다시 뒤에 넣었을 때
        {
            priorities.push_back(tmp); // 뺀 거 다시 맨 뒤로 넣기
            if(location < 0) // 원하던 게 맨 앞꺼였으면
                location = priorities.size()-1; // 위치 재조정
        }
        else // 실행됐을 때
        {
            answer++; // 실행된 수
            if(location < 0) // 원하던 게 맨 앞꺼였으면
                return answer;
        }
    }    
}