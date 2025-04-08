#include <bits/stdc++.h>
using namespace std;

int N, M, K;

long long solve(int sx, int sy, int ex, int ey){
    int a=ex-sx, b=ey-sy;
    
    long long res=1;
    for(int i=a+b; i>max(a, b); i--){
        res*=i;
    }
    
    long long temp=1;
    for(int i=min(a, b); i>1; i--){
        temp*=i;
    }
    
    return res/temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>K;
    if(K==0){
        cout<<solve(1, 1, N, M);
        return 0;
    }
    
    int tarX=(K-1)/M, tarY=(K-1)%M;
    long long ans=solve(0, 0, tarX, tarY) * solve(tarX, tarY, N-1, M-1);
    cout<<ans;
}