#include <bits/stdc++.h>
using namespace std;

int N, l=0, cnt=0, ans=0;
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>S;
    for(int i=0; i<N; i++){
        if(S[i]=='P'){
            if(cnt==1) l=2;
            else l=1-l;
        } else{
            cnt++;
            if(cnt==2){
                if(l==0) ans=5;
                else if(l==1) ans=1;
                else ans=6;
            }
        }
    }
    cout<<ans;
}