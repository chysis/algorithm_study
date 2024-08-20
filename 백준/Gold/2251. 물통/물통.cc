#include <iostream>
#include <tuple>
#include <queue>
#include <set>
#include <algorithm>

#define INF 987654321
using namespace std;

int capa[3], cur[3];
bool ans[201];
queue<pair<int, int>> q;
bool visited[201][201]; // A, B에 들어있는 양
int dS[6]={0, 0, 1, 1, 2, 2};
int dE[6]={1, 2, 0, 2, 0, 1};

void solve(){
    while(!q.empty()){
        cur[0]=q.front().first;
        cur[1]=q.front().second;
        cur[2]=capa[2]-cur[0]-cur[1];
        q.pop();
        
        int next[3];
        for(int i=0; i<6; i++){
            for(int j=0; j<3; j++){
                next[j]=cur[j];
            }
            
            if(capa[dE[i]]-cur[dE[i]]>=cur[dS[i]]){
                next[dS[i]]=0;
                next[dE[i]]=cur[dS[i]]+cur[dE[i]];
            } else{
                next[dS[i]]=cur[dS[i]]-(capa[dE[i]]-cur[dE[i]]);
                next[dE[i]]=capa[dE[i]];
            }
            
            if(next[dS[i]]<0 || next[dE[i]]<0) continue;
            if(next[dS[i]]>capa[dS[i]] || next[dE[i]]>capa[dE[i]]) continue;
            
            if(!visited[next[0]][next[1]]){
                if(next[0]==0) ans[next[2]]=true;
                visited[next[0]][next[1]]=true;
                q.push({next[0], next[1]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<3; i++){
        cin>>capa[i];
    }
    q.push({0, 0});
    ans[capa[2]]=true;
    visited[0][0]=true;
    solve();
    
    for(int i=0; i<201; i++){
        if(ans[i]) cout<<i<<" ";
    }
}