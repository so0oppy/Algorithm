#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    // callings를 하나씩 돌면서, 해당 이름에 해당하는 players의 인덱스랑 바로 앞 이름 인덱스랑 변환
    // players를 pair벡터로 저장, 불린 이름의 int값이랑 바로 앞 int값 바꿔서 저장, 반복한 다음 int값에 따라 sort
    int size_p = players.size();
    unordered_map<string, int> runners(size_p); // {{mumu, 1},{soe, 2},{poe,3},...}
    
    for(int i=0; i<size_p; i++)
    {
        runners[players[i]] = i+1; // 각 선수마다 등수 저장
    }
    for(auto c: callings)
    {
        // 불린 선수 몇 번째인지 num에 저장
        int num = runners[c];
        if(num > 1) // 불린 선수가 첫 번째가 아니라면
        {
            // 불린 선수는 num-1로 저장, num-1번째 선수는 num으로 저장
            string prev = players[num-2];
            swap(players[num-1], players[num-2]);
            // pair 업데이트
            runners[c] = num-1;
            runners[prev] = num;
        }
    }
    
    return players;
}