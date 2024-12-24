#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    // '('이 나오면 push, ')'이 나오면 pop을 함 (empty일 경우 pop이 안 되므로 false)
    // 모든 문자를 다 돌았는데도 empty가 아니면 남았다는 의미이므로 false
    vector<int> stack;
    for(char c: s)
    {
        if(c == '(')
        {
            stack.push_back(1);
        }
        else if(c == ')')
        {
            if(stack.empty()) 
                answer = false;
            else
                stack.pop_back();
        }
    }
    
    if(!stack.empty()) answer = false;
    
    return answer;
}