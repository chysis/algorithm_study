#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, ans=INF;
char arr[51][51];
tuple<int, int, int> colors[51];

void solve(int start, int end){
    int res=0;
    // paint W
    for(int i=0; i<start; i++){
        res+=(get<1>(colors[i])+get<2>(colors[i]));
    }
    
    // paint B
    for(int i=start; i<=end; i++){
        res+=(get<0>(colors[i])+get<2>(colors[i]));
    }
    
    // paint R
    for(int i=end+1; i<N; i++){
        res+=(get<0>(colors[i])+get<1>(colors[i]));
    }
    
    ans=min(ans, res);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int w=0, b=0, r=0;
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='W') w++;
            else if(arr[i][j]=='B') b++;
            else r++;
        }
        colors[i]={w, b, r};
    }
    
    for(int i=1; i<N-1; i++){
        for(int j=i; j<N-1; j++){
            solve(i, j);
        }
    }
    cout<<ans;
}