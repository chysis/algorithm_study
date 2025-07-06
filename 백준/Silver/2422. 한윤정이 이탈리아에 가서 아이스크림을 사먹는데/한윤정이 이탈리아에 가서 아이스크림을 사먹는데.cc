#include <bits/stdc++.h>
using namespace std;

int N, M, X, Y, sel[4], ans=0;
vector<int> v[201];
bool visited[201];

void solve(int cnt, int prev){
    if(cnt==3){
        if(find(v[sel[0]].begin(), v[sel[0]].end(), sel[1])!=v[sel[0]].end()) return;
        if(find(v[sel[0]].begin(), v[sel[0]].end(), sel[2])!=v[sel[0]].end()) return;
        if(find(v[sel[1]].begin(), v[sel[1]].end(), sel[2])!=v[sel[1]].end()) return;
        ans++;
        return;
    }
    
    for(int i=prev; i<=N; i++){
        if(!visited[i]){
            visited[i]=true;
            sel[cnt]=i;
            solve(cnt+1, i);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>X>>Y;
        if(X<Y) v[X].push_back(Y);
        else v[Y].push_back(X);
    }
    
    solve(0, 1);
    cout<<ans;
}