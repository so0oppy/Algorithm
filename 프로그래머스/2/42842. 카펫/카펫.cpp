#include <string>
#include <vector>

using namespace std;
// 가로 길이 >= 세로 길이
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // yellow의 세로 길이 * 2 + yellow의 가로 길이 * 2 + 4 = brown 갯수
    int yellow_col, yellow_row; // 세로, 가로
    int yellow_sum; // 가로 + 세로
    int yellow_mul; // 가로 * 세로
    yellow_sum = (brown - 4) / 2;
    yellow_mul = yellow;
    
    for(yellow_col = 1; yellow_row >= yellow_col; yellow_col++)
    {
        yellow_row = yellow_sum - yellow_col;
        if(yellow_mul == yellow_row * yellow_col)
        {
            answer.push_back(yellow_row+2);
            answer.push_back(yellow_col+2);
            break;
        }
    }
    
    return answer;
}