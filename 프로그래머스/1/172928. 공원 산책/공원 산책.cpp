#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    bool find = false;
    int h=-1, w=-1; // 세로, 가로
    int park_h = park.size(); // 공원 세로
    int park_w = park[0].length(); // 공원 가로
    // result는 park의 인덱스
    // E는 같은 string내에서 오른쪽으로 인덱스 이동
    // W는 같은 string내에서 왼쪽으로 인덱스 이동
    // N은 다른 string에서 위로 같은 인덱스 이동
    // S는 다른 string에서 아래로 같은 인덱스 이동 (만약 string을 벗어나거나, X를 만나면 다음 명령어로 이동)
    for(auto p: park)
    {
        h++;
        w = -1;
        for(int i=0; i<park_w; i++)
        {
            w++;
            if(p[i] == 'S') 
            {
                find = true;
                break;
            }
        }
        if(find) break;
    }
    cout << "S위치 h : "<< h << " w : "<< w << endl;
    for(string rt: routes)
    {
        if(rt[0] == 'E')
        {
            int temp = w; // 돌아갈 곳 임시 저장
            for(int i=0; i<rt[2]-'0'; i++)
            {
                ++w;
                if(w+1 > park_w) // 공원을 나가게 되면
                {
                    cout<< "공원을 나간 w : " << w << endl;
                    w = temp; // 이동 취소하고
                    cout << "되돌린 w : " << w << endl;
                    break; // 다음 명령으로 이동
                }
                if(park[h][w] == 'X') // 가는 길에 장애물을 만나게 되면
                {
                    w = temp; // 이동 취소하고
                    break; // 다음 명령으로 이동
                }
            }
            cout << "E이동 h : "<< h << " w : "<< w << endl;            
        }
        else if(rt[0] == 'W')
        {
            int temp = w; // 돌아갈 곳 임시 저장
            for(int i=0; i<rt[2]-'0'; i++)
            {
                w--;
                if(w < 0) // 공원을 나가게 되면
                {
                    w = temp; // 이동 취소하고
                    break; // 다음 명령으로 이동
                }
                if(park[h][w] == 'X') // 가는 길에 장애물을 만나게 되면
                {
                    w = temp; // 이동 취소하고
                    break; // 다음 명령으로 이동
                }
            }
            cout << "W이동 h : "<< h << " w : "<< w << endl;
        }
        else if(rt[0] == 'N')
        {
            int temp = h; // 돌아갈 곳 임시 저장
            for(int i=0; i<rt[2]-'0'; i++)
            {
                h--;
                if(h < 0) // 공원을 나가게 되면
                {
                    h = temp; // 이동 취소하고
                    break; // 다음 명령으로 이동
                }
                if(park[h][w] == 'X') // 가는 길에 장애물을 만나게 되면
                {
                    h = temp; // 이동 취소하고
                    break; // 다음 명령으로 이동
                }
            }
            cout << "N이동 h : "<< h << " w : "<< w << endl;
        }
        else if(rt[0] == 'S')
        {
            int temp = h; // 돌아갈 곳 임시 저장
            for(int i=0; i<rt[2]-'0'; i++)
            {
                h++;
                if(h+1 > park_h) // 공원을 나가게 되면
                {
                    h = temp; // 이동 취소하고
                    break; // 다음 명령으로 이동
                }
                if(park[h][w] == 'X') // 가는 길에 장애물을 만나게 되면
                {
                    h = temp; // 이동 취소하고
                    break; // 다음 명령으로 이동
                }
            }
            cout << "S이동 h : "<< h << " w : "<< w << endl;
        }
    }
    answer.push_back(h);
    answer.push_back(w);
    
    return answer;
}