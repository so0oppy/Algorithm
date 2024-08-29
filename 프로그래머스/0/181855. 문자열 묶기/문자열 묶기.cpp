#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
    // 문자열 길이에 따라 나뉜 문자열 개수를 담은, 길이가 30인 목록
    int list[30] = {0}; //예- 길이 1이면 list[0]에, ..., 길이 30이면 list[29]의 숫자 ++;
    int answer = list[0];
    
    for(auto& s: strArr)
    {
        list[s.length()-1]++;
    }
    for(int i=0; i<30; i++)
    {
        if(list[i] > answer)
            answer = list[i];
    }
    
    return answer;
}