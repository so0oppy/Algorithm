#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset<int> high;
    
    for(int i=0; i< score.size(); i++)
    {
        high.insert(score[i]);
        if(high.size() > k)
            high.erase(high.begin()); // k개 초과하여 자동 정렬됐을 때 최소값 삭제
        
        answer.push_back(*high.begin()); // 자동 정렬됐을 때 맨 앞이 최소값
    }

    return answer;
}