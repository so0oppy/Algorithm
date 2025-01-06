#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 한 번에 "2명씩" 밖에 못 탐 (문제 잘 읽기)
int solution(vector<int> people, int limit) {
    int answer = 0;
    int start = 0; // 가벼운 사람부터
    int end = people.size()-1; // 무거운 사람부터
    int sum = 0;
    
    sort(people.begin(), people.end()); // 정렬
    // [30, 30, 30, 30, 40, 50], 100
    while(start <= end)
    {
        int sum = people[start] + people[end];
        if(sum <= limit)
        {
            start++;
            end--;
        }
        else if(sum > limit)
        {
            end--;
        }
        answer++;
    }
    
    
    return answer;
}