#include <bits/stdc++.h>
using namespace std;

int N, M, H, arr[11][11], adj[11][11], ans=0;
pair<int, int> home;
vector<pair<int, int>> mincho;
bool visited[11];

bool canGoHome(int num, int hp){
    return abs(mincho[num].first-home.first)+abs(mincho[num].second-home.second)<=hp;
}

void solve(int curNum, int curHp, int cnt){
    if(canGoHome(curNum, curHp)){
        ans=max(ans, cnt);
    }
    
    for(int i=0; i<mincho.size(); i++){
        if(curNum==i || visited[i]) continue;
        if(adj[curNum][i]<=curHp){
            visited[i]=true;
            solve(i, curHp-adj[curNum][i]+H, cnt+1);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>H;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1) home={i, j};
            else if(arr[i][j]==2) mincho.push_back({i, j});
        }
    }
    
    for(int i=0; i<mincho.size(); i++){
        for(int j=0; j<mincho.size(); j++){
            if(i==j) continue;
            adj[i][j]=adj[j][i]=abs(mincho[i].first-mincho[j].first)+abs(mincho[i].second-mincho[j].second);
        }
    }
    
    for(int i=0; i<mincho.size(); i++){
        if(ans==mincho.size()) break;
        if(canGoHome(i, M)){
            int dist=abs(mincho[i].first-home.first)+abs(mincho[i].second-home.second);
            visited[i]=true;
            solve(i, M-dist+H, 1);
            visited[i]=false;
        }
    }
    
    cout<<ans;
}