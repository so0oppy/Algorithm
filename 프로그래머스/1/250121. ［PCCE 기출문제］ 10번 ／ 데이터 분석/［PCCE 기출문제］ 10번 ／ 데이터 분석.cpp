#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    // data[i][0] -> code, [1]->date, [2]->maximum, [3]->remain
    int ext_index;
    if(ext == "code") ext_index = 0;
    else if(ext == "date") ext_index = 1;
    else if(ext == "maximum") ext_index = 2;
    else if(ext == "remain") ext_index = 3;
    int sort_index;
    if(sort_by == "code") sort_index = 0;
    else if(sort_by == "date") sort_index = 1;
    else if(sort_by == "maximum") sort_index = 2;
    else if(sort_by == "remain") sort_index = 3;
    
    for(auto d: data)
    {
        if(d[ext_index] < val_ext)
        {
            answer.push_back(d);
        }
    }
    // sort_by (정렬 기준)
    sort(answer.begin(), answer.end(), [&](const vector<int> &v1, const vector<int> &v2){
        return v1[sort_index] < v2[sort_index];
    });
    
    return answer;
}