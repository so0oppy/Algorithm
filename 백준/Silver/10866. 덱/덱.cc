#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> DQ;
    int N;
    cin >> N;
    
    while(N--){
        string op;
        cin >> op;
        
        if(op == "push_front"){
            int X;
            cin >> X;
            DQ.push_front(X);
        }
        else if(op == "push_back"){
            int X;
            cin >> X;
            DQ.push_back(X);
        }
        else if(op == "pop_front"){
            if(DQ.empty()) cout << -1 << '\n';
            else{
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }
        else if(op == "pop_back"){
            if(DQ.empty()) cout << -1 << '\n';
            else{
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }
        else if(op == "size"){
            cout << DQ.size() << '\n';
        }
        else if(op == "empty"){
            cout << (int)DQ.empty() << '\n';
        }
        else if(op == "front"){
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.front() << '\n';
        }
        else if(op == "back"){
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.back() << '\n';
        }
    }
}