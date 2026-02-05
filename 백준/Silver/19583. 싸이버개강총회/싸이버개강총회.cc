#include <bits/stdc++.h>
using namespace std;

string S, E, Q, T, N;
int start_time, end_time, s_end_time, ans=0;
set<string> reg;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S>>E>>Q;
    start_time=stoi(S.substr(0, 2))*60+stoi(S.substr(3, 2));
    end_time=stoi(E.substr(0, 2))*60+stoi(E.substr(3, 2));
    s_end_time=stoi(Q.substr(0, 2))*60+stoi(Q.substr(3, 2));
    
    while(cin>>T>>N){
        int t=stoi(T.substr(0, 2))*60+stoi(T.substr(3, 2));
        if(t<=start_time) reg.insert(N);
        else if(t>=end_time && t<=s_end_time){
            auto it=reg.find(N);
            if(it!=reg.end()){
                ans++;
                reg.erase(it);
            }
        }
    }
    
    cout<<ans;
}