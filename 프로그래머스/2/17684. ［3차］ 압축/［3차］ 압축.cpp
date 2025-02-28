#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    
    for(int i=0; i<26; i++)
    {
        string s(1, 'A' + i);  // "A" ~ "Z"
        dict[s] = i+1;
    }
    
    int dictIndex = 27; // 새로운 인덱스 번호
    int i = 0;

    while(i < msg.length())
    {
        string tmp = "";
        int index;
        
        while(i < msg.length())
        {
            tmp += msg[i];
            
            if(dict.find(tmp) != dict.end()) // 찾았다면
            {
                index = dict[tmp];
                i++;
            }
            else // 못 찾았다면
                break;
        }
        answer.push_back(index);
        
        if(i < msg.length())
            dict[tmp] = dictIndex++;
    }
    
    return answer;
}