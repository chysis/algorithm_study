#include <bits/stdc++.h>
using namespace std;

int N, M, arr[2][3], ans=0;

void solve(int day, int place, int work, int score){
    if(day==N){
        if(score>=M) ans++;
        return;
    }
    
    solve(day+1, 0, 0, score+(place==0 ? arr[0][0]/2 : arr[0][0]));
    solve(day+1, 0, 1, score+(place==0 ? arr[1][0]/2 : arr[1][0]));
    solve(day+1, 1, 0, score+(place==1 ? arr[0][1]/2 : arr[0][1]));
    solve(day+1, 1, 1, score+(place==1 ? arr[1][1]/2 : arr[1][1]));
    solve(day+1, 2, 0, score+(place==2 ? arr[0][2]/2 : arr[0][2]));
    solve(day+1, 2, 1, score+(place==2 ? arr[1][2]/2 : arr[1][2]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    
    solve(1, 0, 0, arr[0][0]);
    solve(1, 0, 1, arr[1][0]);
    solve(1, 1, 0, arr[0][1]);
    solve(1, 1, 1, arr[1][1]);
    solve(1, 2, 0, arr[0][2]);
    solve(1, 2, 1, arr[1][2]);
    cout<<ans;
}