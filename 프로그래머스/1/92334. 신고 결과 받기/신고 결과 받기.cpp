#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0); // 각 유저별로 받을 결과 메일 수를 저장할 벡터
    map<string, int> complaint;            // 각 ID가 받은 신고 횟수
    map<string, set<string>> id_report;    // 유저가 신고한 ID 목록 (중복 방지 위해 set 사용)

    // report에서 신고한 유저와 신고당한 유저를 분리하여 id_report와 complaint에 기록
    for (auto r : report) {
        stringstream ss(r);
        string reporter, reported;
        ss >> reporter >> reported;  // 공백을 기준으로 문자열을 나눔

        // 동일 유저가 중복 신고하지 않도록 체크
        if (id_report[reporter].insert(reported).second) { // 새로운 신고면 true 반환
            complaint[reported]++; // 신고당한 ID의 신고 횟수 증가
        }
    }

    // 신고받은 횟수가 k 이상인 유저를 신고한 유저에게 메일 횟수 증가
    for (int i = 0; i < id_list.size(); i++) {
        string user = id_list[i];
        if (complaint[user] >= k) {  // 신고 횟수가 기준 이상일 때
            for (const auto& reporter : id_report) {
                if (reporter.second.count(user)) { // user를 신고한 적이 있는 reporter만 체크
                    answer[find(id_list.begin(), id_list.end(), reporter.first) - id_list.begin()]++;
                }
            }
        }
    }

    return answer;
}
