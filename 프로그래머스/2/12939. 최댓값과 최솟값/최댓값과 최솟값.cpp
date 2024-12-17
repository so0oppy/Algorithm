#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> sortNum; // 공백으로 구분해서 하나씩 여기에 집어 넣음
    
    stringstream ss(s);
    string temp;
    
    while(ss >> temp)
    {
        sortNum.push_back(stoi(temp));
    }
        
    int minNum = *min_element(sortNum.begin(), sortNum.end()); 
    int maxNum = *max_element(sortNum.begin(), sortNum.end());
    
    answer = to_string(minNum) + ' ' + to_string(maxNum); 
    
    return answer;
}