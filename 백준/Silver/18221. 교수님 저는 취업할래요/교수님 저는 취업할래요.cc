#include <bits/stdc++.h>
using namespace std;

int N, arr[1001][1001];
double sx, sy, px, py;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j]==2) sx=i, sy=j;
            else if(arr[i][j]==5) px=i, py=j;
        }
    }
    
    if(sqrt(pow(sx-px, 2)+pow(sy-py, 2))<5) return cout<<0, 0;
    
    int cnt=0;
    for(int i=min(sx, px); i<=max(sx, px); i++){
        for(int j=min(sy, py); j<=max(sy, py); j++){
            if(arr[i][j]==1) cnt++;
        }
    }
    
    if(cnt>=3) cout<<1;
    else cout<<0;
}