#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    bool done = true; // 단어가 끝났는지
    for(auto& c: s)
    {
        if(c == ' ') // 공백이면 단어가 끝난 것
        {
            done = true;
            continue; // 아래 코드 실행 안 함
        }
        if(c >= '0' && c <= '9') // 숫자일 경우 
        {
            done = false; // 첫 단어 끝남
            continue; // 아래 코드 실행 안 함
        }
        if(done) // 첫 단어이자 숫자가 아닐 경우
        {
            c = toupper(c); // 대문자 처리
            done = false; // 첫 단어 끝남
            continue; // 아래 코드 실행 안 함
        }
        // 이외는 전부 소문자 처리
        c = tolower(c);
    }
    
    answer = s;
    return answer;
}