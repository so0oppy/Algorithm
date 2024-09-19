#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    // vector<pair<char, string>> 이용
    // char를 기준으로 sort, 만약 char가 같다면, pair의 string을 비교
    sort(strings.begin(), strings.end(), [n](const string &a, const string &b) {
        // n번째 문자가 같으면 사전순으로 정렬
        if (a[n] == b[n]) {
            return a < b;
        }
        // n번째 문자를 기준으로 정렬
        return a[n] < b[n];
    });

    return strings; // 정렬된 결과 반환
}