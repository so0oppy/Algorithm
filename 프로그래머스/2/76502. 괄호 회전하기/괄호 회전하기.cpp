#include <string>
#include <vector>
#include <stack>

using namespace std;
bool isValid(string s){
    stack<int> st;
    
    for(auto c: s)
    {
        if(c == '[' || c == '{' || c == '(')
            st.push(c);
        else
        {
            if(st.empty()) 
                return false;
            char top = st.top();
            // 짝이 맞지 않는 경우
            if((c==']' && top!='[') || 
                   (c=='}' && top!='{') ||
                (c==')' && top!='('))
                return false;
            else
                st.pop(); // 짝이 맞는 경우
        }
    }
    return st.empty();  // 비어있다는 건 짝이 다 맞다는 뜻
}

int solution(string s) {
    int answer = 0;
    // 스택 사용
    for(int x=0; x<s.length(); x++)
    {
        if(isValid(s)) ++answer; // 올바른 괄호 문자열 갯수
        
        s = s.substr(1) + s[0]; // 문자열 회전
    }
    return answer;
}