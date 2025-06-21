#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>S;
        
        int cnt=0;
        bool flag=true;
        for(int i=0; i<S.length()/2; i++){
            if(S[i]==S[S.length()-1-i]) cnt++;
            else{
                flag=false;
                break;
            }
        }
        
        if(flag) cout<<1<<" "<<cnt+1<<"\n";
        else cout<<0<<" "<<cnt+1<<"\n";
    }
}