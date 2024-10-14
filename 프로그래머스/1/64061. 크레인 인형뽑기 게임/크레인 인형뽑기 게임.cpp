#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0; // 터트려져 사라진 인형 개수 (2의 배수)
    // vector<vector<int>> column(5, vector<int> (5, 0));// 세로 배열로 저장
    vector<int> store; // 이전 인형 저장
    // // board의 뒤에서부터 column에 push_back
    // for(int i=board.size()-1; i >= 0; i--)
    // {
    //     for(int j=0; j<board[i].size(); j++)
    //     {
    //         int b = board[i][j];
    //         column[j][board.size()-i-1] = b;
    //     }
    // }
    // board내 배열의 index를 0부터 검사해서 0이 아닌 수가 나오면 doll에 저장
    // 저장 후엔 해당 수를 0으로 변환
    for(int m: moves)
    {
        int doll = 0;
        int row = 0;
        
        for(int i=0; i<board.size(); i++)
        {
            if(board[row][m-1] == 0)
                row++;
            else
            {
                doll = board[row][m-1];
                board[row][m-1] = 0;
                break;
            }
        }
        
        if(doll == 0)
            continue;
        else
        {
            // 이전 doll과 현재 doll이 같으면 answer+=2, store가 가리키는 인형은 앞으로 이동
            if(!store.empty() && store.back() == doll)
            {
                cout << doll << endl;
                answer += 2;
                store.pop_back(); // 현재 넣으려는 doll과 함께 store의 마지막 부분 pop
            }
            else store.push_back(doll);
        }
    }
    return answer;
}