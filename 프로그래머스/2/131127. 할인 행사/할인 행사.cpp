#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isSatisfied(map<string, int>& want_list) {
    for (auto& w : want_list) {
        if (w.second > 0) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> want_list;

    // 초기 맵 생성
    for (int i = 0; i < want.size(); i++) {
        want_list[want[i]] = number[i];
    }

    // 슬라이딩 윈도우 방식으로 확인
    for (int start = 0; start <= discount.size() - 10; ++start) {
        // 현재 상태를 복사해서 사용
        map<string, int> current_list = want_list;

        // 10일 간의 할인 상품 확인
        for (int i = start; i < start + 10; ++i) {
            if (current_list.find(discount[i]) != current_list.end()) {
                current_list[discount[i]]--; // 원하는 상품일 경우 수량 감소
            }
        }

        // 모든 원하는 상품의 수량이 만족되면 구매 가능
        if (isSatisfied(current_list)) {
            answer++;
        }
    }

    return answer;
}
