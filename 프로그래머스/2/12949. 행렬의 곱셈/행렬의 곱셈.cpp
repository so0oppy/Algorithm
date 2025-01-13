#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int rows1 = arr1.size();          // arr1의 행 크기
    int cols1 = arr1[0].size();       // arr1의 열 크기
    int cols2 = arr2[0].size();       // arr2의 열 크기

    // 결과 행렬 초기화: arr1의 행 개수 x arr2의 열 개수
    vector<vector<int>> answer(rows1, vector<int>(cols2, 0));

    // 행렬 곱셈 수행
    for (int i = 0; i < rows1; i++) {          // arr1의 행
        for (int j = 0; j < cols2; j++) {      // arr2의 열
            for (int k = 0; k < cols1; k++) {  // arr1의 열 == arr2의 행
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return answer;
}