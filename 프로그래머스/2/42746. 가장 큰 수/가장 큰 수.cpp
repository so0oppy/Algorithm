#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    // 가장 왼쪽 수가 큰 수부터 정렬
    // 각 수를 string으로 변환
    // 두 문자를 더했을 때의 결과를 cmp로 비교
    for(int i=0; i<numbers.size(); i++)
    {
        str.push_back(to_string(numbers[i]));
    }
    // 만약 첫 수가 같다면 그 다음 왼쪽 수 비교
    sort(str.begin(), str.end(), cmp);
    
    for(auto s: str)
    {
        answer += s;
    }
    
    if(answer == string(answer.length(), '0')) // 0으로만 이뤄졌을 경우
        answer = "0";
    
    return answer;
}