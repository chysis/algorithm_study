#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

int N, M;
int groupCnt=0;
vector<int> group[101];
bool done[101];
bool visited[101];
bool adj[101][101];
int floyd[101][101][101];

void dfs(int start){
    group[groupCnt].push_back(start);
    done[start]=true;
    visited[start]=true;
    
    for(int i=1; i<=N; i++){
        if(i==start) continue;
        if(!visited[i] && adj[start][i]){
            dfs(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    
    for(int i=0; i<M; i++){
        int A, B;
        cin>>A>>B;
        adj[A][B]=true;
        adj[B][A]=true;
    }
    
    for(int i=1; i<=N; i++){
        if(done[i]) continue;
        else {
            groupCnt++;
            dfs(i);
        }
    }
    
    for(int i=1; i<=groupCnt; i++){
        sort(group[i].begin(), group[i].end());
    }
    
    for(int k=1; k<=groupCnt; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i==j) floyd[k][i][j]=0;
                else if(adj[i][j]) floyd[k][i][j]=1;
                else floyd[k][i][j]=INF;
            }
        }
    }
    
    for(int l=1; l<=groupCnt; l++){
        for(int k=0; k<group[l].size(); k++){
            for(int i=0; i<group[l].size(); i++){
                for(int j=0; j<group[l].size(); j++){
                    int a=group[l][k];
                    int b=group[l][i];
                    int c=group[l][j];
                    floyd[l][b][c]=min(floyd[l][b][c], floyd[l][b][a]+floyd[l][a][c]);
                }
            }
        }
    }
    
    cout<<groupCnt<<"\n";
    
    vector<int> ans;
    for(int i=1; i<=groupCnt; i++){
        int res=INF, resIdx;
        for (int j=0; j<group[i].size(); j++) {
            int temp=-1;
            int tempIdx;
            int member=group[i][j];
            for (int k=0; k<group[i].size(); k++) {
                if (temp<floyd[i][member][group[i][k]]) {
                    temp=floyd[i][member][group[i][k]];
                    tempIdx=group[i][j];
                }
            }
            if (res>temp) {
                res=temp;
                resIdx=tempIdx;
            }
        }
        ans.push_back(resIdx);
    }
    
    sort(ans.begin(), ans.end());
    for(auto a: ans) cout<<a<<"\n";
}