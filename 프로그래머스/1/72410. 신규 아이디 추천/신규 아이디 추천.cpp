#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
// 아이디 길이 : 3~15
// 아이디 : 알파벳 소문자, 숫자, '-', '_', '.' 만 사용 가능
// 마침표('.')는 처음/끝에 사용 X , 연속 사용 X
string solution(string new_id) {
    string answer = "";
    
    for(char& c: new_id)
    {
        if(isupper(c)) // 대문자라면
            c = tolower(c); // 소문자로 변환
    }
    cout << "1 : "<< new_id << endl;
    for(char& c : new_id)
    {
        if(islower(c) || c == '-' || c == '_' || c == '.' || isdigit(c)) // 사용 가능한 문자이면
            answer += c;
    }
    cout << "2 : "<< answer << endl;
    
    string tmp;
    for(int i=0; i<answer.length(); i++)
    {
        // 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
        if(answer[i] == '.')
        {
            if(i == 0)
                tmp += answer[i];
            else if(i>0 && answer[i-1] != '.') // 첫 마침표면
            {
                tmp += answer[i]; // tmp에 더하기 (연속된 마침표면 더해지지 않음)
            }
        }
        else
            tmp += answer[i];
    }
    answer = tmp;
    cout << "3 : " << answer << endl;
    
    if(answer.front() == '.') //마침표(.)가 처음이나 끝에 위치한다면 제거
        answer.erase(answer.begin());
    
    if(answer.back() == '.')
        answer.pop_back();
    cout << "4 : " << answer << endl;
    
    // 빈 문자열이라면, new_id에 "a"를 대입
    if(answer.empty())
        answer = 'a';
    cout << "5 : "<< answer << endl;
    
    // 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
    if(answer.length() >= 16)
    {
        answer = answer.substr(0, 15);
        // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거
        if(answer.back() == '.')
            answer.pop_back();
    }
    cout << "6 : "<< answer << endl;
    
    // 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙임
    if(answer.length() <= 2)
    {
        while(answer.length() != 3)
            answer += answer.back();
    }
    cout << "7 : "<< answer << endl;
    
    return answer;
}