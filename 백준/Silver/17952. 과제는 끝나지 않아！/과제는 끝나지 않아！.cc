#include <bits/stdc++.h>
using namespace std;

int N, A, T, ans=0;
stack<pair<int, int>> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        int opt; cin>>opt;
        if(opt==1){
            cin>>A>>T;
            s.push({A, T});
        }
        
        if(!s.empty()){
            auto& cur=s.top();
            cur.second--;
            if(cur.second==0){
                ans+=cur.first;
                s.pop();
            }
        }
    }
    
    cout<<ans;
}