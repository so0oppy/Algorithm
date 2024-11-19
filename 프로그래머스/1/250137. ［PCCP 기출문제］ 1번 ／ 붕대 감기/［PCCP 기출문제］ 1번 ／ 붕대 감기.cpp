#include <string>
#include <vector>

using namespace std;
// t초동안 붕대 -> 1초마다 x만큼 회복
// t초 연속 붕대 -> y만큼 추가 회복
// 공격 당하면 기술 취소, 당하는 순간에 회복X, 연속 성공 시간 0으로 초기화 (0이하 되면 죽음)
// bandage = {기술 시전 시간, 1초당 회복량, 추가 회복량}
// health = 최대 체력, attacks = {{공격 시간, 피해량}, ...}
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int max_health = health; // 최대 체력 저장
    int count = 0; // 연속 공격 카운트
    int size_attacks = attacks.size();
    int final_attack = attacks[size_attacks-1][0]; // 몬스터의 마지막 공격 시간
    int time_attack = 0; // attacks의 인덱스
    
    for(int time=1; time<= final_attack; time++)
    {
        if(time == attacks[time_attack][0]) // 현재 시간이 공격 시간이랑 같으면 공격
        {
            health -= attacks[time_attack][1]; // 공격
            if(time_attack < size_attacks-1) time_attack++; // 다음 공격이 있을 때만 인덱스 넘어감
            count = 0; // 연속 성공 초기화
        }
        else // 공격 시간이 아니면
        {
            ++count; // 연속 성공
            // 현재 체력 + 회복량 
            if(count == bandage[0])
            {
                // count가 기술 시전 시간이 되면 0으로 초기화 및 회복량+추가 회복량 얻음
                health += bandage[1] + bandage[2];
                count = 0;
            }
            else
            {
                health += bandage[1];
            }
            if(health > max_health) health = max_health; // 최대이상 체력 못가짐
        }
        if(health <= 0) return -1; // 죽었을 경우 -1 반환
    }
    
    answer = health;
    return answer; // 모든 공격이 끝난 직후 남은 체력
}