#include <bits/stdc++.h>
using namespace std;

int N, M;
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>S;
    int cnt=M;
    for(int i=0; i<N; i++){
        if(S[i]=='0') continue;
        int target=10-(S[i]-'0');
        if(target<=cnt){
            cnt-=target;
            S[i]='0';
        }
    }
    S[S.length()-1]=(((S[S.length()-1]-'0')+cnt)%10)+'0';
    cout<<S;
}