#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int sum1 = 0;
    int sum2 = 0;
    // arr1 < arr2 -> -1
    // arr1 > arr2 -> 1
    // arr1 = arr2 -> 합 비교, 더 큰 쪽이 크면 위 조건 고려, 같으면 0
    
    if(arr1.size() > arr2.size())
        return 1;
    else if(arr1.size() < arr2.size())
        return -1;
    else
    {
        for(auto i: arr1)
            sum1 += i;
        for(auto i: arr2)
            sum2 += i;
        if(sum1 > sum2)
            return 1;
        else if(sum1 < sum2)
            return -1;
        else 
            return 0;
    }
}