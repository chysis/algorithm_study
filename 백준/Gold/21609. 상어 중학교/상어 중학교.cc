#include <bits/stdc++.h>
using namespace std;

int N, M, arr[21][21], score=0;
vector<int> groupArr[21][21];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<pair<int, int>> q;
bool visited[21][21], rainbowVisited[21][21];

// return # of block of group starts with (i, j)
int bfs(int i, int j, int color, int groupNum){
    memset(rainbowVisited, false, sizeof(rainbowVisited));
    q={};
    
    q.push({i, j});
    visited[i][j]=true;
    groupArr[i][j].push_back(groupNum);
    
    int blockCnt=1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            if(arr[nx][ny]!=color && arr[nx][ny]!=0) continue;
            if(arr[nx][ny]==0) {
                if(rainbowVisited[nx][ny]) continue;
                rainbowVisited[nx][ny]=true;
            } else {
                if(visited[nx][ny]) continue;
                visited[nx][ny]=true;
            }
            
            q.push({nx, ny});
            blockCnt++;
            groupArr[nx][ny].push_back(groupNum);
        }
    }
    
    return blockCnt;
}

// delete target from group array
void deleteFromGroupArr(int target){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            groupArr[i][j].erase(
              remove(groupArr[i][j].begin(), groupArr[i][j].end(), target),
              groupArr[i][j].end()
            );
        }
    }
}

void initGroupArr(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            groupArr[i][j].clear();
        }
    }
}

// return found group count 
int findGroup(){
    memset(visited, false, sizeof(visited));
    initGroupArr();
    int groupNum=1;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] || arr[i][j]<=0) continue;

            int res=bfs(i, j, arr[i][j], groupNum);
            if(res>=2) groupNum++;
            else deleteFromGroupArr(groupNum);
        }
    }
    
    return groupNum-1;
}

struct GroupInfo{
    int groupNum;
    pair<int, int> basis;
    int blockTotal;
    int rainbowBlock;
};

GroupInfo findBiggestGroup(int groupCnt){
    GroupInfo res;
    res.basis={-1, -1};
    res.blockTotal=0;
    res.rainbowBlock=0;
    
    for(int num=1; num<=groupCnt; num++){
        int cnt=0, rainbow=0;
        pair<int, int> start={-1, -1};
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(find(groupArr[i][j].begin(), groupArr[i][j].end(), num)!=groupArr[i][j].end()){
                    cnt++;
                    if(arr[i][j]>0 && start.first==-1 && start.second==-1) start={i, j};
                    if(arr[i][j]==0) rainbow++;
                }
            }
        }
        
        if(res.blockTotal<cnt){
            res.groupNum=num;
            res.basis=start;
            res.blockTotal=cnt;
            res.rainbowBlock=rainbow;
        } else if(res.blockTotal==cnt){
            if(res.rainbowBlock<rainbow){
                res.groupNum=num;
                res.basis=start;
                res.blockTotal=cnt;
                res.rainbowBlock=rainbow;
            } else if(res.rainbowBlock==rainbow){
                if(res.basis.first<start.first){
                    res.groupNum=num;
                    res.basis=start;
                    res.blockTotal=cnt;
                    res.rainbowBlock=rainbow;
                } else if(res.basis.first==start.first){
                    if(res.basis.second<start.second){
                        res.groupNum=num;
                        res.basis=start;
                        res.blockTotal=cnt;
                        res.rainbowBlock=rainbow;
                    }
                }
            }
        }
    }
    
    return res;
}

void gravity(){
    for(int i=N-1; i>=0; i--){
        for(int j=0; j<N; j++){
            if(arr[i][j]==-1) continue;
            
            int x=i;
            while(true){
                x++; // see next line
                if(x==N || arr[x][j]!=-2){
                    x--;
                    break;
                }
            }
            
            if(x!=i) swap(arr[x][j], arr[i][j]);
        }
    }
}

void rotateArr(){
    int tempArr[21][21];
    
    for(int i=N-1; i>=0; i--){
        for(int j=0; j<N; j++){
            tempArr[N-1-i][j]=arr[j][i];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j]=tempArr[i][j];
        }
    }
}

void deleteGroup(int groupNum){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(find(groupArr[i][j].begin(), groupArr[i][j].end(), groupNum)!=groupArr[i][j].end()){
                arr[i][j]=-2; // deleted mark
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    
    while(true){
        int groupCnt=findGroup();
        if(groupCnt==0) break;
        
        auto biggestGroup=findBiggestGroup(groupCnt);
        deleteGroup(biggestGroup.groupNum);
        score+=biggestGroup.blockTotal*biggestGroup.blockTotal;

        gravity();
        rotateArr();
        gravity();
    }
    
    cout<<score;
}