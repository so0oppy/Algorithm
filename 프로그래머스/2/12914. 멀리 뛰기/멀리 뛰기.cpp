#include <string>
#include <vector>

using namespace std;
// 1, 2, 3, 5, 8, 13, ...
// dp(n) = dp(n-1) + dp(n-2)
long long solution(int n) {
    long long answer = 0;
    vector<int> dp(3, 0); // n-2, n-1, n
    dp[0] = 1;
    dp[1] = 2;
    if(n==1) return 1;
    if(n==2) return 2;
    for(int i=2; i<n; i++)
    {
        dp[2] = (dp[0] + dp[1]) % 1234567; // 구할 값
        dp[0] = dp[1]; // 현재였던 값으로 이전 값 업데이트
        dp[1] = dp[2]; // 구한 값으로 현재 값 업데이트
    }
    answer = dp[2];
    
    return answer;
}