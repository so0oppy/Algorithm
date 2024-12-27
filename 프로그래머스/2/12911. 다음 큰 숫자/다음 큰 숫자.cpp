#include <string>
#include <bitset>

using namespace std;

int solution(int n) {
    int numOnes = bitset<32>(n).count(); // 현재 숫자의 1의 개수
    while (true) {
        n++; // 다음 숫자로 증가
        if (bitset<32>(n).count() == numOnes) { // 1의 개수가 같으면 반환
            return n;
        }
    }
}
