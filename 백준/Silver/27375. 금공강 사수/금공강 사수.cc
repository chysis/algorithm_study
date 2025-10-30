#include <bits/stdc++.h>
using namespace std;

int N, K, W, S, E, sel[21], ans=0;
vector<tuple<int, int, int>> arr;
bool selected[21];

bool isValid(int size){
    bool used[5][11];
    memset(used, false, sizeof(used));
    
    for(int i=0; i<size; i++){
        int day=get<0>(arr[sel[i]]);
        int stime=get<1>(arr[sel[i]]);
        int etime=get<2>(arr[sel[i]]);
        for(int i=stime; i<=etime; i++){
            if(used[day][i]) return false;
            used[day][i]=true;
        }
    }
    return true;
}

void solve(int size, int cnt, int prev, int score){
    if(size==cnt){
        if(score!=K) return;
        if(isValid(size)) ans++;
        return;
    }
    
    for(int i=prev+1; i<arr.size(); i++){
        if(!selected[i]){
            selected[i]=true;
            sel[cnt]=i;
            int day=get<0>(arr[i]);
            int stime=get<1>(arr[i]);
            int etime=get<2>(arr[i]);
            solve(size, cnt+1, i, score+(etime-stime+1));
            selected[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>W>>S>>E;
        if(W!=5) arr.push_back({W, S, E});
    }
    
    for(int i=1; i<=N; i++){
        solve(i, 0, -1, 0);
    }
    cout<<ans;
}