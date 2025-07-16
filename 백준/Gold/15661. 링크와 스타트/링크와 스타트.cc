#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, arr[21][21], sel[11], ans=INF;
bool visited[21];

void solve(int target, int cnt, int prev){
    if(cnt==target){
        vector<int> v;
        for(int i=0; i<sel[0]; i++) v.push_back(i);
        for(int i=0; i<target-1; i++){
            for(int j=sel[i]+1; j<sel[i+1]; j++) v.push_back(j);
        }
        for(int i=sel[target-1]+1; i<N; i++) v.push_back(i);
        
        int selSum=0, remainSum=0;
        for(int i=0; i<target; i++){
            for(int j=i+1; j<target; j++){
                selSum+=arr[sel[i]][sel[j]];
                selSum+=arr[sel[j]][sel[i]];
            }
        }
        
        for(int i=0; i<N-target; i++){
            for(int j=i+1; j<N-target; j++){
                remainSum+=arr[v[i]][v[j]];
                remainSum+=arr[v[j]][v[i]];
            }
        }
        
        ans=min(ans, abs(selSum-remainSum));
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
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int size=1; size<=10; size++){
        solve(size, 0, 0);
    }
    cout<<ans;
}