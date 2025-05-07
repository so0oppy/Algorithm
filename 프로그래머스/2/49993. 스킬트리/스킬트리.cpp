#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    // skill_trees 원소마다 한 문자씩 skill에서 찾고, 찾으면 그 문자를 skill에서 지움
    // 따라서 위치가 0이 아니면 불가능 스킬트리
    for(auto st: skill_trees)
    {
        string s = skill;
        bool possible = true;
        for(int i=0; i<st.length(); i++)
        {
            if(s.find(st[i]) != string::npos)
            {
                if(s[0] == st[i])
                {
                    s.erase(s.begin());
                }
                else if(s[0] != st[i])
                {
                    possible = false;
                    break;
                }
                if(s.empty()) break;
            }
        }
        if(possible) answer++;
    }
    
    
    return answer;
}