#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothes_map; // [{headgear, 2}, {eyewear, 1}]
    
    for(auto c: clothes)
    {
        clothes_map[c[1]]++;
    }
    
    for(auto cm: clothes_map)
    {
        if(clothes_map.size() == 1)
            return cm.second;
        else
            answer *= (cm.second + 1);
    }
    answer -= 1;
    
    return answer;
}