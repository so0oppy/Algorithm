#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> countX(10,0), countY(10,0);
    // 공통으로 나타나는 정수를 큰 수부터 정렬해서 return
    // 공통으로 나타나는 정수 없으면 -1 return
    for(char x: X)
    {
        countX[x-'0']++;
    }
    for(char y: Y)
    {
        countY[y-'0']++;
    }
    // 공통으로 나타나는 정수 찾기(countX, countY 중에 min값만큼 answer에 해당 수 넣기)
    for(int i=0; i<countX.size(); i++)
    {
        for(int j=0; j<min(countX[i], countY[i]); j++)
        {
            answer += i + '0'; // char형태로 string에 추가
        }
    }
    
    // 큰 수부터 정렬
    if(answer != "")
        sort(answer.begin(), answer.end(), greater<>());
    else // 비어있으면 -1 return
        answer = "-1";
    while(1)
    {
        if(answer[0] == '0' && answer.length() > 1)
            answer.erase(answer.begin());
        else
            return answer;
    }
}