#include <bits/stdc++.h>
using namespace std;

int N, M, ans=0;
bool arr[26][26];

void solve(int cnt){
    if(cnt==N*M){
        ans++;
        return;
    }
    
    int x=cnt/M;
    int y=cnt%M;
    
    solve(cnt+1); // 현재 칸 배치 안 하는 경우
    
    if(x>0 && y>0 && arr[x-1][y] && arr[x][y-1] && arr[x-1][y-1]) return;
    arr[x][y]=true;
    solve(cnt+1);
    arr[x][y]=false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    solve(0);
    
    cout<<ans;
}