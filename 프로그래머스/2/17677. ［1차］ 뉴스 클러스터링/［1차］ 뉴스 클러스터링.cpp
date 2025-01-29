#include <string>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    map<string, int> mp1, mp2; // 중복 갯수 세기 위함
    // 모두 대문자로 변경하기
    // 다중집합 형성
    for (int i = 1; i < str1.length(); i++) {
        char a = toupper(str1[i - 1]);
        char b = toupper(str1[i]);
        if (isalpha(a) && isalpha(b)) {
            string tmp = string(1, a) + string(1, b);
            mp1[tmp]++;
        }
    }
    for (int i = 1; i < str2.length(); i++) {
        char a = toupper(str2[i - 1]);
        char b = toupper(str2[i]);
        if (isalpha(a) && isalpha(b)) {
            string tmp = string(1, a) + string(1, b);
            mp2[tmp]++;
        }
    }
    // 교집합, 합집합 계산 {["FR", 2], ["RE", 1], ...} {["FR", 1], ["RA", 1], ...}
    int inter_size = 0, uni_size = 0;
    for (const auto& [key, val] : mp1) {
        if (mp2.count(key)) { // 겹치는 게 있을 때
            inter_size += min(val, mp2[key]);
            uni_size += max(val, mp2[key]);
        }
        else uni_size += val; // 없을 때
    }
    for (const auto& [key, val] : mp2) {
        if (!mp1.count(key)) { // 겹치는 게 없을 때
            uni_size += val;
        }
    }
    // 자카드 유사도 계산
    double jaccard = (uni_size == 0) ? 1.0 : (double) inter_size / uni_size;
    
    return (int)(jaccard*65536);
}