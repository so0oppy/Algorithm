#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    // 1. 해시맵 생성
    unordered_map<string, bool> phone_map;

    // 2. 모든 전화번호를 해시맵에 저장
    for (const string& phone : phone_book) {
        phone_map[phone] = true;
    }

    // 3. 각 전화번호의 접두어가 해시맵에 있는지 확인
    for (const string& phone : phone_book) {
        string prefix = "";
        for (size_t i = 0; i < phone.size(); i++) {
            prefix += phone[i]; // 접두어를 하나씩 늘려가며 확인
            if (prefix != phone && phone_map.find(prefix) != phone_map.end()) {
                return false; // 접두어가 해시맵에 존재하면 false 반환
            }
        }
    }

    return true; // 접두어 관계가 없으면 true 반환
}