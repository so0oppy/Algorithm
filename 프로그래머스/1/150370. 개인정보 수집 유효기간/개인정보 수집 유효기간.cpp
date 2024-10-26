#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    // privacies의 각 string의 마지막 자리수로 terms 각 string의 첫 자리수와 비교해서 찾음
    // terms내 string의 2번째 자리부터 끝까지를 숫자로 변환 (int num_t)
    // 자른 string에서 0~3번째 자리: int year, 5~6번째 자리:int month, 8~9번째: int day 
    // month에 num_t 더하기 (month += num_t)
    // month 값이 12를 초과하면, month %= 12, year += month/12 , day는 그대로
    // today의 0~3번째 먼저 비교, 5~6번째 다음으로 비교 한 뒤, today값이 더 크다면 answer에 저장
    int i=1;
    
    for(string p: privacies)
    {
        int num_t, year, month, day;
        for(string t: terms)
        {
            if(p.back() == t.front())
                num_t = stoi(t.substr(2));
        }
        cout << num_t << endl;
        year = stoi(p.substr(0, 4));
        month = stoi(p.substr(5, 2));
        day = stoi(p.substr(8, 2));
        cout << "year: "<< year <<" month: "<< month <<" day: "<< day << endl;
        
        month += num_t;
        year += (month-1)/12;
        month = (month-1)%12 +1;
        cout <<"year: "<< year << " month: "<< month << endl;
        
        int t_year = stoi(today.substr(0, 4));
        int t_month = stoi(today.substr(5, 2));
        int t_day = stoi(today.substr(8, 2));
        
        if(t_year > year)
            answer.push_back(i);
        else if(t_year == year && t_month > month)
            answer.push_back(i);
        else if(t_year == year && t_month == month && t_day >= day)
            answer.push_back(i);

        i++;
    }
    
    return answer;
}