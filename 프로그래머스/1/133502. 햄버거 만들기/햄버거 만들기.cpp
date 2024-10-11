#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    // 빵(1)-야채(2)-고기(3)-빵(1) -> 1 2 3 1 순서
    // 4개씩 잘라서 1,2,3,1 찾으면 삭제하고 다시 1,2,3,1 찾기
    vector<int> stack; // 햄버거 쌓을 스택
    for(int i: ingredient)
    {
        stack.push_back(i);
        if(stack.size() >= 4)
        {
            if(stack[stack.size()-4] == 1 && stack[stack.size()-3] == 2 &&
                  stack[stack.size()-2] == 3 && stack[stack.size()-1] == 1)
            {
                answer++;
                stack.erase(stack.end()-4, stack.end());
            }
        }
    }
    
    return answer;
}