#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b){ // (장르, 총 재생 횟수)
    return a.second > b.second;
}
bool cmp2(const pair<int, int>& a, const pair<int, int>& b){ // (재생횟수, 고유번호)
    if(a.first == b.first) return a.second < b.second; // 재생 횟수가 같으면 고유번호 작은 순서
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, unordered_multimap<int, int>> songs; // 장르, {재생횟수, 고유번호}
    map<string, int> total; // 장르, 총 재생 횟수
    // 1. 가장 많이 재생된 장르 먼저 , 그 중 탑2
    // 2. [{classic, {{800,3}, {500, 0}, {150, 2}}}, {pop, {{2500, 4}, {600, 1}}}]
    for(int i=0; i<plays.size(); i++)
    {
        songs[genres[i]].insert({plays[i], i});
        total[genres[i]] += plays[i];
    }
    // 가장 많이 재생된 순서로 장르 구하기
    vector<pair<string, int>> vec(total.begin() ,total.end());
    sort(vec.begin(), vec.end(), cmp); // [{pop, 3100}, {classic, 1450}]
    
    // 해당 장르의 탑2를 인덱스로 answer에 저장
    for(auto& v: vec)
    {
        string genre = v.first;
        int count = 0;
        
        vector<pair<int, int>> song(songs[genre].begin() ,songs[genre].end());
        sort(song.begin(), song.end(), cmp2);
        
        for(auto& s: song)
        {
            answer.push_back(s.second);
            count++;
            if(count == 2) break;
        }
    }
    
    return answer;
}