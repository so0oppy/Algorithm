#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    vector<int> temp; // 일차원 배열
    
    for (long long i = left; i <= right; ++i) {
        // i번째 값을 2D 배열에서의 행(row)과 열(col)로 변환
        long long row = i / n; // 행 번호
        long long col = i % n; // 열 번호

        // 값은 max(row, col) + 1
        answer.push_back(max(row, col) + 1);
    }
    
    return answer;
}