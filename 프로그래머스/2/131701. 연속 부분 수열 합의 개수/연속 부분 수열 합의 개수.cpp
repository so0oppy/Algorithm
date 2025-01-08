#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> numbers; // 합들을 여기 저장해두면 자동으로 겹치는 수는 없어짐
    int Size = elements.size();
    vector<vector<int>> dp(Size, vector<int>(Size));
    
    for(int i=0; i < elements.size(); i++)
    {
        dp[0][i] = elements[i];
        numbers.insert(dp[0][i]);
    }
    
    for(int i=1; i < elements.size(); i++)
    {
        for(int j=0, k=i; j<elements.size(); ++j, k = (k==Size-1)? 0 : ++k)
        {
            dp[i][j] = dp[i-1][j] + dp[0][k];
            numbers.insert(dp[i][j]);
        }
    }
    
    answer = numbers.size();
    
    return answer;
}