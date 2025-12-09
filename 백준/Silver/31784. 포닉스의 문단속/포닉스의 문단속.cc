#include <bits/stdc++.h>
using namespace std;

int N, K;
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K>>S;
    for(int i=0; i<N; i++){
        if(S[i]=='A'){
            if(i!=N-1) continue;
            else S[i]=(S[i]-'A'+K)%26+'A'; // 마지막 자리가 A인 경우
        }else{
            if(i==N-1) {
                S[i]=(S[i]-'A'+K)%26+'A';
                break;
            }
            
            int offset=S[i]-'A';
            if(K>=26-offset){
                K-=(26-offset);
                S[i]='A';
            }
        }
    }
    cout<<S;
}