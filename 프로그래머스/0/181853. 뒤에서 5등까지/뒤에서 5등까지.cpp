#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    sort(num_list.begin(), num_list.end()); // 오름차순으로 정렬
    // 이후 앞의 5개의 수 떼내면..
    for(int i=0; i<5; i++)
    {
        answer.push_back(num_list[i]);
    }
    
    return answer;
}