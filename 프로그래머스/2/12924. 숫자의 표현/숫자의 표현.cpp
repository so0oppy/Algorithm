#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    // n = a+(a+1)+(a+2)+...+(a+k-1) = a*k + k(k-1)/2
    // a = (n-k(k-1)/2) / k (a > 0 자연수)
    for(int k=1; k*(k-1)/2 < n; ++k)
    {
        if((n-k*(k-1)/2) % k == 0) answer++;
    }
    
    return answer;
}