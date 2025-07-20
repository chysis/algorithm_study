#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

ll N, S, B, sel[11], ans=LLONG_MAX;
pii arr[11];
bool visited[11];

void solve(int target, int cnt, int prev){
    if(target==cnt){
        ll totalS=1, totalB=0;
        for(int i=0; i<target; i++){
            totalS*=arr[sel[i]].first;
            totalB+=arr[sel[i]].second;
        }
        ans=min(ans, abs(totalS-totalB));
        return;
    }
    
    for(int i=prev; i<N; i++){
        if(!visited[i]){
            visited[i]=true;
            sel[cnt]=i;
            solve(target, cnt+1, i);
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
        cin>>S>>B;
        arr[i]={S, B};
    }
    
    for(int size=1; size<=N; size++){
        solve(size, 0, 0);
        memset(visited, false, sizeof(visited));
    }
    
    cout<<ans;
}