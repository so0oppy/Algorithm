#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // 정렬한 뒤, 하나의 값 이상의 숫자들 갯수 = h편 인 것들 중 최대가 H-Index
    sort(citations.begin(), citations.end());
    // [0, 2, 4, 5, 8] 5개, 3편의 논문이 3회 이상 (o) / 2편의 논문은 5회 이상 (x)
    //  0  1  2  3  4
    for(int i=0; i<citations.size(); i++)
    {
        if(citations.size() - i <= citations[i])
            answer++;
    }
    
    return answer;
}