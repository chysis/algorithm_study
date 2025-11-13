#include <bits/stdc++.h>
using namespace std;

int T, N, K;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N>>K;
        if(K>1){
            for(int i=1; i<=N; i++) cout<<i<<" ";
            cout<<"\n";
        }else{
            if(N==2 || N==3) cout<<"-1"<<"\n";
            else{
                for(int i=2; i<=N; i+=2) cout<<i<<" ";
                for(int i=1; i<=N; i+=2) cout<<i<<" ";
                cout<<"\n";
            }
        }
    }
}