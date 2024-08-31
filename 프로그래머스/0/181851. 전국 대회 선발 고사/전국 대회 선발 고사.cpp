#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    int f=0;
    vector<int> result;
    
    for(int i=1; i<= rank.size(); i++)
    {
        if(result.size() == 3)
            break;
        f = find(rank.begin(), rank.end(), i) - rank.begin();
        if(attendance[f] == true)
            result.push_back(f);
    }
    
    answer = 10000*result[0] + 100*result[1] + result[2];
    
    return answer;
}