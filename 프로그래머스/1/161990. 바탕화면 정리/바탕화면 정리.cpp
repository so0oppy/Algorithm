#include <string>
#include <vector>
#include <limits> // numeric_limits 사용을 위해 필요

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4); // [lux, luy, rdx, rdy]
    // '#'저장해둔 files에서 i값이 가장 작은 (key, value) pair를 lux, 가장 큰 pair를 rdx+1
    // j값이 가장 작은 pair를 luy, 가장 큰 pair를 rdy+1
    int lux = numeric_limits<int>::max(); // 최소값
    int luy = numeric_limits<int>::max();
    int rdx = numeric_limits<int>::min(); // 최대값
    int rdy = numeric_limits<int>::min();
    
    for(int i=0; i<wallpaper.size(); i++)
    {
        for(int j=0; j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                lux = min(lux, i);
                rdx = max(rdx, i+1);
                luy = min(luy, j);
                rdy = max(rdy, j+1);
            }
        }
    }
    
    answer[0] = lux;
    answer[1] = luy;
    answer[2] = rdx;
    answer[3] = rdy;
    
    return answer;
}