#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    // 1, 4, 7 -> R
    // 3, 6, 9 -> L
    // 2, 5, 8, 0 -> 이전 손가락 위치에 따름 (같으면 hand에 따름)
    // *은 10, 0은 11, #은 12로 변환
    // (현재 위치한 수 - 목표 숫자)의 절댓값을 구한 뒤
    // 이 절댓값을 3으로 나눈 몫( 위나 아래로 갈 때 3씩 변함 )과 3으로 나눈 나머지( 왼쪽 오른쪽으로 갈 때 마다 1씩 변함 )를 더한 값이 이동 횟수
    int dist_r = 0, dist_l = 0;
    int pos_r = 10, pos_l = 12;
    for(int i=0; i<numbers.size(); i++)
    {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {    
            answer += 'L';
            pos_l = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {    
            answer += 'R';
            pos_r = numbers[i];
        }
        else 
        {
            if(numbers[i] == 0)
                numbers[i] = 11;
            dist_r = (abs(pos_r - numbers[i]) % 3) + (abs(pos_r - numbers[i]) / 3);
            dist_l = (abs(pos_l - numbers[i]) % 3) + (abs(pos_l - numbers[i]) / 3);
            
            if(dist_r < dist_l)
            {
                answer += 'R';
                pos_r = numbers[i];
            }
            else if(dist_r > dist_l)
            {
                answer += 'L';
                pos_l = numbers[i];
            }
            else
            {
                if(hand == "right")
                {
                    answer += 'R';
                    pos_r = numbers[i];
                }
                else
                {
                    answer += 'L';
                    pos_l = numbers[i];
                }
            }
        }
    }
    
    return answer;
}