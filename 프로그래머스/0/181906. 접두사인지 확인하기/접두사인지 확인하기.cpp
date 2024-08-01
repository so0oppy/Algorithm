#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    
    return answer = my_string.substr(0, is_prefix.size()) == is_prefix ? 1 : 0;
}