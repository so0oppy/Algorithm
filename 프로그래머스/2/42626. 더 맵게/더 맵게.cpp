#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순
    
    for(auto s: scoville)
    {
        pq.push(s);
    }
    
    while(true)
    {
        if(pq.top() >= K) break;
        if(pq.size() == 1 && pq.top() < K) return -1;
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + (b * 2);
        pq.push(c);
        
        answer++;
    }
    
    return answer;
}