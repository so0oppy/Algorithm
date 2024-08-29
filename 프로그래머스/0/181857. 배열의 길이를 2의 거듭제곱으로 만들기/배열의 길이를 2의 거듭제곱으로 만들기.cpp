#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int n=1;
    // 2를 계속 곱하다가 arr.size와 같으면 그대로 리턴, arr.size보다 커진 순간의 값 저장한 다음, 그 값에 도달할 때까지 0추가?
    while(n < arr.size())
    {
        n *= 2;
    }
    
    arr.resize(n, 0); // 길이를 n으로 만든 다음, 그 길이에 맞을 때까지 0 추가
    
    return arr;
}

