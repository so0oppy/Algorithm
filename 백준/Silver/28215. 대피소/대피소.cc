#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
int x[50], y[50];
int calc_dist(int i, int j, int k){
    int res = 0;
    for(int h=0; h<n; h++){
        res = max(res, min(min(abs(x[i]-x[h])+abs(y[i]-y[h]), abs(x[j]-x[h])+abs(y[j]-y[h])), 
                  abs(x[k]-x[h])+abs(y[k]-y[h])));
    }
    return res;
}

int main(){
    int answer = 1e9;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    if(k==1){
        for(int i=0; i<n; i++){
            answer = min(answer, calc_dist(i, i, i));
        }
    }
    else if(k==2){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                answer = min(answer, calc_dist(i, j, j));
            }
        }
    }
    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    answer = min(answer, calc_dist(i, j, k));
                }
            }
        }
    }
    cout << answer;
    return 0;
}