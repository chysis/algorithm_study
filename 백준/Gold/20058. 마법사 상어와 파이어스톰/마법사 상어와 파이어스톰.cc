#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N, Q, len;
int map[65][65], tempMap[65][65], level[1001];

queue<pair<int, int>> q;
int chunkCnt=0;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[65][65];

void rotateMap(int lx, int ly, int size){
    int zeroStartMap[65][65];
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            zeroStartMap[i][j]=map[lx+i][ly+j];
        }
    }
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            tempMap[j][size-1-i]=zeroStartMap[i][j];
        }
    }
            
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            map[lx+i][ly+j]=tempMap[i][j];
        }
    }
}

void fireStorm(int level){
    int unitLen=pow(2, level);
    
    for(int i=0; i<len/unitLen; i++){
        for(int j=0; j<len/unitLen; j++){
            rotateMap(i*unitLen, j*unitLen, unitLen);
        }
    }
}

void meltIce(){
    vector<pair<int, int>> candidate;
    
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(map[i][j]==0) continue;
            
            int adjCnt=0;
            for(int k=0; k<4; k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<0 || ny<0 || nx>=len || ny>=len) continue;
                if(map[nx][ny]==0) continue;
                adjCnt++;
            }
            
            if(adjCnt<3) candidate.push_back({i, j});
        }
    }
    
    for(auto a: candidate){
        map[a.first][a.second]--;
    }
}

int countTotalIce(){
    int sum=0;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            sum+=map[i][j];
        }
    }
    
    return sum;
}

void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=len || ny>=len) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny]==0) continue;
            
            q.push({nx, ny});
            visited[nx][ny]=true;
            chunkCnt++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>Q;
    len=pow(2, N);
    
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<Q; i++){
        cin>>level[i];
    }
    
    // 파이어스톰 시전
    for(int i=0; i<Q; i++){
        fireStorm(level[i]);
        meltIce();
    }
    
    int largestIce=0;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(map[i][j]>0 && !visited[i][j]){
                visited[i][j]=true;
                q.push({i, j});
                chunkCnt++;
                bfs();
                
                largestIce=max(largestIce, chunkCnt);
                chunkCnt=0;
            }
        }
    }
    
    cout<<countTotalIce()<<"\n"<<largestIce;
}