#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
   
    for(int i=0; i<n; i++)
    {
        int map = arr1[i] | arr2[i];
        string row = "";
        for(int j=0; j<n; j++)
        {
            if(map & (1 << (n-1-j)))
                row += '#';
            else
                row += ' ';
        }
        answer.push_back(row);
    }
    
    return answer;
}