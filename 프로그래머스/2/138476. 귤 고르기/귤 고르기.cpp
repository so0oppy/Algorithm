#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    // 1. 각 무게별로 몇 개인지 세고 저장
    // 2. 가장 많은 순서로 정렬
    // 3. 귤 개수 - 많은 순서대로 빼기
    // 4. 이 때 종류 구분
    unordered_map<int, int> tang_num;
    vector<int> counts;
    
    for(int t: tangerine)
    {
        tang_num[t]++;
    }
    
    for(auto& pair: tang_num)
    {
        counts.push_back(pair.second);
    }
    sort(counts.begin(), counts.end(), greater<>());
    
    for(int cnt : counts)
    {
        k -= cnt;
        answer++;
        if(k <= 0) break;
    }
    
    return answer;
}