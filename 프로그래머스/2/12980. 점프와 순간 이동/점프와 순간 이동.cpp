#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while(n != 0)
    {
        if(n%2 == 0) // 2로 나눴을 때 나머지 없으면 다시 2로 나눔 (순간이동)
        {
            n /= 2;
        }
        else // 나머지 있으면 -1 (1칸 점프)
        {
            n -= 1;
            ans++;
        }
    }

    return ans;
}