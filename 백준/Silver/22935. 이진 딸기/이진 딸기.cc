#include <bits/stdc++.h>
using namespace std;

int T, N;

string solve(int N){
    string ans="";
    int cnt=0;
    while(N>0){
        if(N%2==0) ans+="V";
        else ans+="O";
        N/=2;
    }
    while(ans.length()!=4) ans+="V";
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N;
        N%=28;
        if(N==0) N=28;
        if(N>15) N=30-N;
        string ans=solve(N);
        for(int i=0; i<ans.length(); i++){
            if(ans[i]=='O') cout<<"딸기";
            else cout<<ans[i];
        }
        cout<<"\n";
    }
}