#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    unordered_map<char, int> test_map= {{'R', 0},{'T', 0}, {'C', 0}, {'F', 0}, {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}};
    string answer = "";
    // survey : 비동의/동의
    // choices : 1(3점) 2(2점) 3(1점) 4(중간) 5(1점) 6(2점) 7(3점)
    // survey의 각 string의 char에 값 저장
    for(int i=0; i<survey.size(); i++)
    {
        if(choices[i] < 4)
        {
            char t = survey[i][0];
            test_map[t] += (4 - choices[i]);
            
            cout << t << test_map[t] << endl;
        }
        else if(choices[i] > 4)
        {
            char t = survey[i][1];
            test_map[t] += (choices[i] - 4);
            
            cout << t << test_map[t] << endl;
        }
        else continue;
    }
    
    if(test_map['R'] >= test_map['T'])
        answer += 'R';
    else
        answer += 'T';
    
    if(test_map['C'] >= test_map['F'])
        answer += 'C';
    else
        answer += 'F';
    
    if(test_map['J'] >= test_map['M'])
        answer += 'J';
    else
        answer += 'M';
    
    if(test_map['A'] >= test_map['N'])
        answer += 'A';
    else
        answer += 'N';
    
    return answer;
}