#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++){
        if(flag[i] == true)
        {
            int n = arr[i]*2;
            while(n--)
                answer.push_back(arr[i]);
        }
        else if(flag[i] == false)
        {
            while(arr[i]--)
                answer.pop_back();
        }
    }
    return answer;
}