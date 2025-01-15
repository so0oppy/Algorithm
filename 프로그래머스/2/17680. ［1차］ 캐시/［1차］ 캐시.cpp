#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> temp;
    
    if(cacheSize == 0)
        return cities.size() * 5;
    
    for(auto c: cities)
    {
        // 대소문자 구분 안 하도록 전부 소문자로 바꾸기 (혹은 전부 대문자로)
        transform(c.begin(), c.end(), c.begin(), ::tolower);
            
        // 캐시 값이 존재한다면, cache hit && 이미 존재하는 값 삭제
        auto it = find(temp.begin(), temp.end(), c);
        if(it != temp.end())
        {
            answer += 1;
            temp.erase(it);
        }
        // 캐시 값이 존재하지 않는다면, cache miss
        else
        {
            answer += 5;
        }
        // 꽉 찼으면 맨 뒷 값 삭제
        if(temp.size() == cacheSize)
        {
            temp.pop_back();   
        }
        // 매번 앞에 새롭게 넣기
        temp.push_front(c);
    }
    
    
    return answer;
}