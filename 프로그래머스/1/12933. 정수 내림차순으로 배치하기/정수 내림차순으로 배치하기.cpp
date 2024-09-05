#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    vector<int> vec;
    string str = "";
    
    while(n)  // n이 0이면 멈춤
    {
        vec.push_back(n % 10);
        n /= 10;
    }
    sort(vec.begin(), vec.end(), greater<>());
    
    for(int c: vec)
    {
        str += to_string(c);  
    }
    
    return stoll(str);
}