#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    vector<vector<int>> dp(park.size(), vector<int>(park[0].size(), 0));
    set<int> numList;
    
    for(int i=0; i<park.size(); i++)
    {
        for(int j=0; j<park[0].size(); j++)
        {
            if(park[i][j] == "-1")
                dp[i][j] = 1;
            else 
                dp[i][j] = 0;
        }
    }
    
    for(int i=1; i<dp.size(); i++)
    {
        for(int j=1; j<dp[0].size(); j++)
        {
            if(dp[i][j] == 0) continue;
            
            dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            numList.insert(dp[i][j]);
        }
    }
    
    int mx = -1;
    for(int m: mats)
    {
        if(numList.find(m) != numList.end())
            mx = max(mx, m);
    }
    
    answer = mx;
    return answer;
}