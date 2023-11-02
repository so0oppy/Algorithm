#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, X, A[10005];
    
    std::cin >> N >> X;
    
    for(int i=0; i<N; i++) std::cin >> A[i];
    for(int i=0; i<N; i++){
        if(A[i] < X){
            std::cout << A[i] << ' ';
        }
    }
    
}