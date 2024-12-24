#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    // A는 가장 작은 수부터, B는 가장 큰 수부터 서로 곱하면 최소 될 듯
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    for(int i=0; i<A.size(); i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}