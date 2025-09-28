#include <bits/stdc++.h>
using namespace std;

int w, sum=0;
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S;
    for(int i=0; i<S.length(); i++){
        if(S[i]=='*'){
            w=i%2==0 ? 1 : 3;
            continue;
        }
        sum+=((S[i]-'0')*(i%2==0 ? 1 : 3));
    }
    
    for(int i=0; i<10; i++){
        if((sum+i*w)%10==0){
            cout<<i;
            break;
        }
    }
}