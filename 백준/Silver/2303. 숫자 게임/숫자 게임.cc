#include <bits/stdc++.h>
using namespace std;

int N, card[1001][6], sel[4], maxVal[1001];
bool visited[6];

void solve(int friendId, int cnt){
    if(cnt==3){
        int temp=0;
        for(int i=0; i<3; i++) temp+=card[friendId][sel[i]];
        maxVal[friendId]=max(maxVal[friendId], temp%10);
        return;
    }
    
    for(int i=0; i<5; i++){
        if(!visited[i]){
            visited[i]=true;
            sel[cnt]=i;
            solve(friendId, cnt+1);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<5; j++){
            cin>>card[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        solve(i, 0);
    }
    
    int maxAns=*max_element(maxVal, maxVal+N);
    for(int i=N-1; i>=0; i--){
        if(maxVal[i]==maxAns){
            cout<<i+1;
            break;
        }
    }
}