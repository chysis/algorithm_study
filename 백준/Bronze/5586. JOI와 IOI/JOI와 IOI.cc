#include <bits/stdc++.h>
using namespace std;

string S;
int jcnt=0, icnt=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S;
    for(int i=0; i<S.length()-2; i++){
        if(S[i]=='J' && S[i+1]=='O' && S[i+2]=='I') jcnt++;
        else if(S[i]=='I' && S[i+1]=='O' && S[i+2]=='I') icnt++;
    }
    cout<<jcnt<<"\n"<<icnt;
}