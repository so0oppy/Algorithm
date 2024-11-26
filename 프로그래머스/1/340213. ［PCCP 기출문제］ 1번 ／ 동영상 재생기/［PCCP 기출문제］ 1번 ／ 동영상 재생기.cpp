#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 시간을 초 단위로 변환하는 함수
int timeToSeconds(const string& time) {
    int minutes = stoi(time.substr(0, 2));
    int seconds = stoi(time.substr(3, 2));
    return minutes * 60 + seconds;
}

// 초를 "mm:ss" 형식의 문자열로 변환하는 함수
string secondsToTime(int totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    string mm = (minutes < 10 ? "0" : "") + to_string(minutes);
    string ss = (seconds < 10 ? "0" : "") + to_string(seconds);
    return mm + ":" + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int videoSeconds = timeToSeconds(video_len);
    int posSeconds = timeToSeconds(pos);
    int opStartSeconds = timeToSeconds(op_start);
    int opEndSeconds = timeToSeconds(op_end);

    // 명령어 처리
    for (const string& command : commands) {
        if (command == "prev") {
            posSeconds = max(0, posSeconds - 10);
        } else if (command == "next") {
            // 오프닝 구간 확인
            if (posSeconds >= opStartSeconds && posSeconds <= opEndSeconds) {
                posSeconds = opEndSeconds; // 오프닝 끝으로 이동
            }
            posSeconds = min(videoSeconds, posSeconds + 10);
        }

        // 오프닝 건너뛰기
        if (posSeconds >= opStartSeconds && posSeconds <= opEndSeconds) {
            posSeconds = opEndSeconds; // 오프닝 끝으로 이동
        }
    }

    // 결과 반환
    return secondsToTime(posSeconds);
}
