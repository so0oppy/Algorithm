#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a;
    cin >> a;
    
    stack<char> s;
    
    int n = 0; //잘려진 조각
    bool isRay = true;
    for(auto c: a){
        if(c == '('){
            s.push(c);
            isRay = true;
        }
        else if(c == ')'){
            if(isRay){
                s.pop();
                n += s.size();
                isRay = false;
            } 
            else{
                s.pop();
                n += 1;
            }
        }
    }
    cout << n;
}