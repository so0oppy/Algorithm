#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// 더 많은 선물을 준 사람
// if(기록 없거나 주고받은 수 같다면) 선물 지수가 더 큰 사람
// if(선물 지수까지 같다면 주고받지 않음)

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0; // 가장 많은 선물을 받는 친구가 받을 선물의 수
    map<vector<string>, int> gifts_num; // {[받은 사람, 준 사람], 선물 갯수}
    map<string, int> give; // 준 사람, 준 선물 갯수
    map<string, int> receive; // 받은 사람, 받은 선물 갯수
    map<string, int> g_indices; // 선물 지수 = 준 선물 - 받은 선물
    vector<int> next_gift(friends.size(), 0); // 사람들마다 다음달에 받을 선물
    
    // gifts_num 완성하기
    for(int i=0; i<friends.size(); i++)
    {
        for(int j=0; j<friends.size(); j++)
        {
            if(i == j) continue;
            vector<string> pair = {friends[i], friends[j]};
            gifts_num[pair] = 0;
        }
    }
    
    // 나머지 map 완성하기
    for(auto g: gifts)
    {
        stringstream in(g);
        string giver, receiver;
        in >> giver >> receiver;
        
        vector<string> pair = {giver, receiver};
        gifts_num[pair] += 1;
        give[giver] += 1;
        receive[receiver] += 1;
    }
    
    // 선물 지수 계산하기 
    for(auto f: friends)
    {
        g_indices[f] = give[f] - receive[f];
    }
    
    // 다음 달에 받을 선물 계산
    for(int i=0; i<friends.size(); i++)
    {
        string g = friends[i]; // 본인
        for(int j=i+1; j<friends.size(); j++)
        {
            string r = friends[j]; // 상대
            vector<string> pair = {g, r}; // 본인->상대
            vector<string> re_pair = {r, g}; // 상대->본인
            if(gifts_num[pair] > gifts_num[re_pair]) // 본인이 상대 더 많이 줬으면
                next_gift[i]++;
            else if(gifts_num[pair] < gifts_num[re_pair]) // 상대가 본인 더 많이 줬으면
                next_gift[j]++;
            else // 서로 주고 받지 않았거나, 같은 수로 선물 주고 받았다면
            {
                if(g_indices[g] > g_indices[r]) // 선물지수 큰 사람
                    next_gift[i]++;
                else if(g_indices[g] < g_indices[r])
                    next_gift[j]++;
                // 선물지수 마저 같다면, 아무 선물도 주고 받지 않음.
            }
        }
    }
    // 가장 많이 받는 친구가 받을 선물 수
    for(auto n: next_gift)
    {
        if(n > answer) answer = n;
    }
    
    return answer;
}