#include <string>
#include <vector>

using namespace std;

int answer = 0;
void dfs(int x, int n, vector<int>& vec, int target){
    if(x == vec.size())
    {
        if(n == target) answer++;
        return;
    }
    dfs(x+1, n+vec[x], vec, target); // 더하기
    dfs(x+1, n-vec[x], vec, target); // 빼기
    return;
}

int solution(vector<int> numbers, int target) {
    
    dfs(0, 0, numbers, target); // 더할 인덱스, 더한 결과    
    
    return answer;
}