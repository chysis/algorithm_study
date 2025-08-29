#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin>>N>>K;
    if(N==1){
        for(int i=0; i<K; i++) cout<<1<<" ";
    } else if(N==2 && K==1){
        cout<<1<<" "<<2;
    } else{
        cout<<-1;
    }
}