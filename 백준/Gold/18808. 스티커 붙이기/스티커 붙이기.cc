#include <bits/stdc++.h>
using namespace std;

int N, M, K, R, C, arr[101][11][11], ans=0;
vector<pair<int, int>> bSize[101];
bool visited[41][41];

bool attach(int num, int rot, int x, int y){
    int H=bSize[num][rot].first;
    int W=bSize[num][rot].second;
    
    if(x+H>N || y+W>M) return false;
    
    // test
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(rot==0){
                if(arr[num][i][j]==1 && visited[x+i][y+j]) return false;
            }else if(rot==1){
                if(arr[num][W-j-1][i]==1 && visited[x+i][y+j]) return false;
            }else if(rot==2){
                if(arr[num][H-i-1][W-j-1]==1 && visited[x+i][y+j]) return false;
            }else{
                if(arr[num][j][H-i-1]==1 && visited[x+i][y+j]) return false;
            }
        }
    }
    
    // attach
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(rot==0){
                if(arr[num][i][j]==1) visited[x+i][y+j]=true;
            }else if(rot==1){
                if(arr[num][W-j-1][i]==1) visited[x+i][y+j]=true;
            }else if(rot==2){
                if(arr[num][H-i-1][W-j-1]==1) visited[x+i][y+j]=true;
            }else{
                if(arr[num][j][H-i-1]==1) visited[x+i][y+j]=true;
            }
        }
    }
    return true;
}

void solve(int num){
    int isDone=false;
    
    for(int rot=0; rot<4; rot++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(attach(num, rot, i, j)){
                    isDone=true;
                    break;
                }
            }
            if(isDone) break;
        }
        if(isDone) break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        cin>>R>>C;
        bSize[i].push_back({R, C});
        bSize[i].push_back({C, R});
        bSize[i].push_back({R, C});
        bSize[i].push_back({C, R});
        for(int j=0; j<R; j++){
            for(int k=0; k<C; k++){
                cin>>arr[i][j][k];
            }
        }
    }
    
    for(int i=0; i<K; i++) {
        solve(i);
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(visited[i][j]) ans++;
        }
    }
    cout<<ans;
}