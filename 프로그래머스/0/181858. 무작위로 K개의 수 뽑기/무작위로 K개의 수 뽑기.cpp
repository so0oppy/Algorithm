#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++)
    {
        if(answer.size() == k)
            break;
        if(find(answer.begin(),answer.end(), arr[i]) == answer.end()) // 이미 저장된 수가 아니라면(못 찾았다면)
            answer.push_back(arr[i]);
    }
    while(k-answer.size())
        answer.push_back(-1);
    
    return answer;
}