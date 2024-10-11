#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same = 0; // 맞춘 개수
    int zero = 0; // 0 개수
    // 똑같은 수만 찾아서 순위 매기기 (낮은 순위, 큰 수)
    // 0 개수를 플러스해서 순위 매기기 (높은 순위, 작은 수)
    for(auto l: lottos)
    {
        if(find(win_nums.begin(), win_nums.end(), l) != win_nums.end()) // 같으면
            ++same;
        else if(l == 0)
            ++zero;
    }
    same += zero;
    if(same == 0 || same == 1) answer.push_back(6);
    else if(same == 2) answer.push_back(5);
    else if(same == 3) answer.push_back(4);
    else if(same == 4) answer.push_back(3);
    else if(same == 5) answer.push_back(2);
    else if(same == 6) answer.push_back(1);
    same -= zero;
    if(same == 0 || same == 1) answer.push_back(6);
    else if(same == 2) answer.push_back(5);
    else if(same == 3) answer.push_back(4);
    else if(same == 4) answer.push_back(3);
    else if(same == 5) answer.push_back(2);
    else if(same == 6) answer.push_back(1);
    
    return answer;
}