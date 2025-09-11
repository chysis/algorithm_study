#include <bits/stdc++.h>
using namespace std;

int T, N, M, ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=N; i<=M; i++){
            string cur=to_string(i);
            for(int j=0; j<cur.length(); j++){
                if(cur[j]=='0') ans++;
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
}