#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    // 1. words 내부를 순환
    // 2. 사람 수만큼 나눠서 현재 차례가 몇 번째인지 파악
    // 3. 만약, 전에 나왔던 단어면 그 즉시 멈추고 반환
    // 4. 만약, 끝말잇기 단어가 틀려도 그 즉시 멈추고 반환
    int num = 0, turn = 0;
    vector<string> temp; // 나왔던 단어들을 저장할 배열
    for(int i=0; i<words.size(); i++)
    {
        num = (i+1) % n;
        if(num == 0) num = n;
        else if(num == 1) turn++; // 1번 차례라면 한 바퀴가 돌았다는 의미
                
        if(i != 0 && (find(temp.begin(), temp.end(), words[i]) != temp.end()
          || words[i-1].back() != words[i].front())) // 이전에 이미 말한 단어이거나, 끝말잇기가 틀렸을 경우 (이 때, i!=0 이어야 함)
        {
            // answer 반환
            answer[0] = num;
            answer[1] = turn;
            break;
        }
        else temp.push_back(words[i]); // 아니라면 temp배열에 저장해둠
    }
    return answer;
}