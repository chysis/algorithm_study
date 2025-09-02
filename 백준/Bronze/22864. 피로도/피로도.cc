#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C, M;
    cin>>A>>B>>C>>M;
    int ans=0, piro=0;
    for(int i=0; i<24; i++){
        if(piro+A<=M){
            piro+=A;
            ans+=B;
        }else{
            piro=max(0, piro-C);
        }
    }
    cout<<ans;
}