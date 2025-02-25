#include <string>
#include <vector>

using namespace std;

string formation(int n, int num)
{
    if (num == 0) return "0";  // 예외 처리
    
    string str="";
    while(num != 0)
    {
        int sub = num % n;
        if(sub >= 10 && sub <= 15)
        {    
            str = char('A' + (sub - 10)) + str;
        }
        else
            str = to_string(sub) + str;
        num /= n;
    }
    
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    // 0부터 커지다가 n이 되는 순간 10으로 변함
    // 16진수는 10~15가 A, B, ... 이고 16이 되면 10으로 변함 ex.26 = 10+16-> 1A
    // m개씩 나눠서 배열에 저장, 모든 배열의 p번째만 구하면 됨
    // 모든 수는 str로 바꾼 뒤 한 자리씩 나눠서 배열에 넣어야 함
    int num = 0; // 현재 숫자
    string seq = "";

    // 필요한 길이(t * m)만큼 숫자를 변환해서 문자열에 저장
    while (seq.length() < t * m) {
        seq += formation(n, num);
        num++;
    }
    
    for (int i = 0; i < t; i++) {
        answer += seq[p - 1 + i * m];  // p번째는 p-1 인덱스
    }
    
    return answer;
}