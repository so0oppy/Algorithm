#include <string>
#include <vector>
#include <cmath>
// 에라토스테네스의 체 이용 : n+1길이의 배열을 만든 후, n보다 작은 수들의 배수에 해당하는 인덱스를 0으로 만든다. 반복한 뒤, 1인 인덱스들만 반환하면 소수를 알 수 있다.  
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> vec(n+1, 1); // 전부 1로 채움
    
    for(int i = 2; i < sqrt(n); i++) // 제곱근 수만큼만 해도 전부 검사 가능
    {
        if(vec[i])
        {
            for(int j=i*i; j<=n; j+=i)  
            {
                vec[j] = 0;
            }
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(vec[i]) answer++;
    }
    
    return answer;
}