#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++)
    {
        if((arr.size()%2 ==0) && (i%2 == 1)) // 짝수 길이이자 홀수 인덱스이면
        {
            arr[i] += n;
        }
        else if((arr.size()%2 ==1) && (i%2 == 0)) // 홀수 길이이자 짝수 인덱스이면
        {
            arr[i] += n;
        }
    }
    
    return arr;
}