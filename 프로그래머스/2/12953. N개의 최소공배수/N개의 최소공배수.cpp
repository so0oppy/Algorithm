#include <string>
#include <vector>

using namespace std;
int gcb(int a, int b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a, int b)
{
    return a*b / gcb(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    // 뒤에서부터 pop으로 2개씩 꺼냄
    // 그 2개의 최소공배수 (lcm) 구한 뒤, arr에 넣음
    // arr길이가 2이상이어야 함. 1개면 해당 수가 lcm
    int a,b,c;
    while(arr.size() >= 2)
    {
        a = arr.back();
        arr.pop_back();
        b = arr.back();
        arr.pop_back();
        c = lcm(a, b);
        arr.push_back(c);
    }
    answer = arr.back();
    
    return answer;
}