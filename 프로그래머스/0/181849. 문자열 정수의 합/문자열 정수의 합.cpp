#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    
    for(char c: num_str)
    {
        int n = c - '0';
        answer += n;
    }
    
    return answer;
}