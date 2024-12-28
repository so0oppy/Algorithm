#include <string>
#include <cmath>

using namespace std;

int countOnes(int m){
    int cnt = 0; // 1의 갯수
    
    while(m>0)
    {
        if(m&1) cnt++; // n의 비트 끝자리가 1인 경우
        m = m >> 1; // n의 비트를 오른쪽으로 한 칸 이동
    }
    return cnt;
}

int solution(int n) {
    int i = 1;
    while(1)
    {
        if(countOnes(n) == countOnes(n+i)) return n+i;
        i++;
    }
    
}