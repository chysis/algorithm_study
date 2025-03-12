#include <bits/stdc++.h>
using namespace std;

int T, N;
char c;
deque<char> dq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>c;
            if(i==0) dq.push_back(c);
            else{
                if(c>dq.front()) dq.push_back(c);
                else dq.push_front(c);
            }
        }
        
        for(auto a: dq) cout<<a;
        cout<<"\n";
        dq.clear();
    }
}