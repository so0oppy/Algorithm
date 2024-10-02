#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) { 
    int answer = 0, shB = 0, lgB = 0, shW = 0, lgW = 0;
    // 가장 긴 쪽, 가장 짧은 쪽 각각 비교
    // 둘 중 하나라도 지갑보다 길다면, 길이가 가장 긴 쪽을 반으로 (/ 사용해서 소수점아래 버림)
    if(bill[0] > bill[1])
    {
        shB = bill[1];
        lgB = bill[0];
    }else
    {
        shB = bill[0];
        lgB = bill[1];
    }
    if(wallet[0] >= wallet[1])
    {
        shW = wallet[1];
        lgW = wallet[0];
    }else
    {
        shW = wallet[0];
        lgW = wallet[1];
    }
    while(shB > shW || lgB > lgW)
    {
        lgB /= 2;
        answer++;
        if(shB > lgB) // 짧은 쪽이 긴 쪽보다 길어지면
            swap(shB, lgB);
    }
    
    return answer;
}