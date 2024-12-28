#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int mod = 1234567;
    int prev = 0; // n-2 번째 피보나치
    int curr = 1; // n-1 번째 피보나치
    
    for (int i = 2; i <= n; i++) {
        int next = (prev + curr) % mod; // n 번째 피보나치 계산
        prev = curr; // 이전 값을 업데이트
        curr = next; // 현재 값을 업데이트
    }
    
    return curr;
}
