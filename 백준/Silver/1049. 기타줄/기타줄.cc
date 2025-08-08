#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, A, B, minA=INF, minB=INF, ans=INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>A>>B;
        minA=min(minA, A);
        minB=min(minB, B);
    }
    
    int g=N%6==0 ? N/6 : N/6+1; // 묶음으로만 살 때
    ans=min({ans, g*minA, (N/6)*minA+(N%6)*minB, N*minB});
    cout<<ans;
}