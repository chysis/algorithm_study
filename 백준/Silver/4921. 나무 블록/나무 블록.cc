#include <bits/stdc++.h>
using namespace std;

string S;
bool m[9][9]={
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 0}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cnt=1;
    while(true){
        cin>>S;
        if(S=="0") break;
        
        if(S[0]!='1' || S[S.length()-1]!='2'){
            cout<<cnt<<". NOT\n";
            cnt++;
            continue;
        }
        
        bool flag=true;
        for(int i=0; i<S.length()-1; i++){
            if(!m[S[i]-'0'][S[i+1]-'0']){
                flag=false;
                break;
            }
        }
        
        if(flag) cout<<cnt<<". VALID\n";
        else cout<<cnt<<". NOT\n";
        
        cnt++;
    }
}