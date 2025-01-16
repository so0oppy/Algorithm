#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> done;
    // 몇 일 걸리는지 정보를 done에 담음
    for(int i=0; i<progresses.size(); i++)
    {
        int days = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0)
            done.push_back(days+1);
        else
            done.push_back(days);
    }
    // 앞 기능이 끝날 때까지 뒷 기능은 배포 불가능
    int max = done[0]; // 첫 기능을 가장 기간이 길다고 가정하고 세운 기준
    int func = 1; // 기능 갯수 (첫 기능 포함)
    for(int i=1; i<done.size(); i++)
    {
        if(done[i] > max) // 배포 전인 앞 기능보다 기간이 길다면 이 기간이 새로운 기준
        {
            max = done[i]; // 기준을 갱신하고
            answer.push_back(func);// 여태 +1 했던 기능 갯수를 answer에 저장
            func = 1; // 다시 1부터 시작 (기준이 바뀌었으므로)
        }
        else // 아직 배포 전인 앞 기능보다 기간이 짧다면
        {
            func++; // 같이 배포될 기능에 추가
        }
    }
    // 마지막에 배포 못 한 기능 묶음을 answer에 추가 저장
    answer.push_back(func);
    
    return answer;
}