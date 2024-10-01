#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> canSay = {"aya", "ye", "woo", "ma"};
    vector<string> cantSay = {"ayaaya", "yeye", "woowoo", "mama"};
    
    for(string b : babbling) {
        bool IsInvalid = false;

        // 연속된 발음을 확인하여 유효하지 않은 단어 처리
        for(string cannot : cantSay) {
            if(b.find(cannot) != string::npos) {    
                IsInvalid = true; // 유효하지 않음
                break; // 반복문 나옴
            }
        }
        if(IsInvalid) continue; // 유효하지 않다면 다음 단어로

        // 발음 가능한 단어 개수 return
    
        int cnt = 1;
        int check = 0; 
            
        for(int j=0; j<b.size(); j++)
        {
            if(b.substr(j, 3) == "aya" && check != 1)
            {
                j+=2;
                check = 1;
            }
            else if(b.substr(j, 2) == "ye" && check != 2)
            {
                j+=1;
                check = 2;
            }
            else if(b.substr(j, 3) == "woo" && check != 3)
            {
                j+=2;
                check = 3;
            }
            else if(b.substr(j, 2) == "ma" && check != 4)
            {
                j+=1;
                check = 4;
            }
            else
            {
                cnt = 0;
                break;
            }
        }
        if(cnt > 0)
            answer++;
    }
    return answer;
}
