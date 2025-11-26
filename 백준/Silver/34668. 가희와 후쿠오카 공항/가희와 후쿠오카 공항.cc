#include <bits/stdc++.h>
using namespace std;

int Q, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>Q;
    while(Q--){
        cin>>M;
        int offset=360;
        offset+=6+12*(M/50);
        if(offset>=1440) cout<<"-1\n";
        else cout<<(offset/60<10?"0":"")<<offset/60<<":"<<(offset%60<10?"0":"")<<offset%60<<"\n";
    }
}