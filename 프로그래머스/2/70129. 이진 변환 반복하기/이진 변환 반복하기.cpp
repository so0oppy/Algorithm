#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    int length = 0; // 0 제거 후 길이
    
    while(s != "1")
    {
        answer[0]++; // 이진 변환 횟수
        
        int zeros = count(s.begin(), s.end(), '0');
        answer[1] += zeros;
        length = s.length() - zeros;
        
        // 이진 변환 결과
        s = ""; 
        while(length > 0)
        {
            s = to_string(length % 2) + s;
            length /= 2;
        }
    }

    return answer;
}