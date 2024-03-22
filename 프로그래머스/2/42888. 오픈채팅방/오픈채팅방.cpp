#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m; //[유저 id: 닉네임]
    
    //들어오고 나가는 활동
    for(int i=0; i<record.size(); i++){
        vector<string> v;
        string str;
        for(int j=0; j<record[i].length(); j++){
            if(record[i][j] == ' '){
                v.push_back(str);
                str = "";
            }
            else{
                str += record[i][j];
                if((j+1) == record[i].length())
                    v.push_back(str);
            }
        }
        //record에 담기
        if(record[i][0] == 'E'){ //Enter
            //이미 있는 사람일 경우, 닉네임만 변경
            if(m.find(v[1]) != m.end()) //찾았다면
                m[v[1]] = v[2]; //map의 v[1]에 해당하는 value값(닉네임)을 v[2](닉네임)로 변경
            else //없는 정보면
                m.insert(pair<string, string> (v[1],v[2])); //map에 v[1]위치에 v[2]값 새로 등록
        }
        if(record[i][0] == 'C'){ //Change
            m[v[1]] = v[2];
        }
    }
    //change까지 반영된 내용을 다시 v에 쪼개서 넣기
    for(int i=0; i<record.size(); i++){
        vector<string> v;
        string str;
        for(int j=0; j<record[i].length(); j++){
            if(record[i][j] == ' '){
                v.push_back(str);
                str = "";
            }
            else{
                str += record[i][j];
                if((j+1) == record[i].length())
                    v.push_back(str);
            }
        }
    
        //최종적으로 해당 메시지 return
        if(record[i][0] == 'E')
            answer.push_back(m[v[1]] + "님이 들어왔습니다.");
        else if(record[i][0] == 'L')
            answer.push_back(m[v[1]] + "님이 나갔습니다.");
    }

    return answer;
}