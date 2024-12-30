#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = -1; 
    string temp;
    temp += s[0];

    for(int i=1; i<s.length(); i++)
    {
        int len = temp.length();
        if(temp[len-1] == s[i])
        {
           temp.pop_back();
        }
        else temp += s[i];
    }
    if(temp.empty()) answer = 1;
    else answer = 0;

    return answer;
}