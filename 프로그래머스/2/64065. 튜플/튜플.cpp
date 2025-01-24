#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int, int>& b){
    if(a.second == b.second) return a.first > b.first;
    else return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer; 
    map<int, int> tuple;
    string n = "";
    bool done = false;
    
    for(auto c: s)
    {
        if (isdigit(c)) // 숫자인지 확인
        { 
            n += c;
        }
        else if(!isdigit(c) && !n.empty()) done = true;
        
        if(done)
        {
            int num = stoi(n); // string을 int로 변환
            tuple[num]++;
            n = ""; // 초기화
            done = false; // 초기화
        }
    }
    // value를 중심으로 map 정렬
    vector<pair<int, int>> vec(tuple.begin(), tuple.end());
    sort(vec.begin(), vec.end(), cmp);
    
    for (auto& p : vec) {
        answer.push_back(p.first);
    }
    
    return answer;
}