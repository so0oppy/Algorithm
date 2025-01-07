#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{   
    int answer = 0;
// 전체 경기 수 = 2루트(인원 수)
// A, B가 홀수번호면 다음 라운드에서 (번호+1)/2 번이 되고
// 짝수 번호면 다음 라운드에서 번호/2 번이 됨
// A < B 였을 경우, A가 홀수, B는 a+1번째 이면 만난 것
// 반대 경우도 마찬가지

    int first_a = a, first_b = b;
    int round = log2(n);
    while(round > 0)
    {
        answer++;
        round--;
        // 만난 경우
        if((first_a < first_b) && (a&1) && a+1 == b) break;
        if((first_a > first_b) && (b&1) && b+1 == a) break;
        // A의 경우
        if((a&1)) a = (a+1)/2;
        else a /= 2;
        // B의 경우
        if((b&1)) b = (b+1)/2;
        else b /= 2;
    }

    return answer;
}