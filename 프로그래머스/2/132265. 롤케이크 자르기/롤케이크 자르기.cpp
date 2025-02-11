#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> piece1;
    unordered_map<int, int> piece2;
    // 
    for(int i=0; i<topping.size(); i++)
    {
        piece1[topping[i]]++;
    }
    for(int i=0; i<topping.size(); i++)
    {
        piece1[topping[i]]--;
        piece2[topping[i]]++;
        
        if(piece1[topping[i]] == 0)
        {
            piece1.erase(topping[i]);
        }
        
        if(piece1.size() == piece2.size()) 
            answer++;
    }
    return answer;
}