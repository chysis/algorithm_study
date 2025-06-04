#include <bits/stdc++.h>
using namespace std;

int H, W, arr[1001][1001], sand[1001][1001];
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
bool visited[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>H>>W;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            char c;
            cin>>c;
            if(c=='.') arr[i][j]=-1;
            else arr[i][j]=c-'0';
        }
    }
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(arr[i][j]==-1 || arr[i][j]==9){
                sand[i][j]=-1;
                continue;
            }
            int cnt=0;
            for(int k=0; k<8; k++){
                int nx=i+dx[k], ny=j+dy[k];
                if(nx<0 || ny<0 || nx>=H || ny>=W) continue;
                if(arr[nx][ny]!=-1) continue;
                cnt++;
            }
            sand[i][j]=cnt;
        }
    }
    
    queue<pair<int, int>> q;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(arr[i][j]==-1 || arr[i][j]==9) continue;
            if(sand[i][j]>=arr[i][j]) {
                visited[i][j]=true;
                q.push({i, j});
            }
        }
    }
    
    int cnt=0;
    while(true){
        int rep=q.size();
        if(rep==0) break;
        
        for(int a=0; a<rep; a++){
            int x=q.front().first;
            int y=q.front().second;
            arr[x][y]=-1;
            q.pop();
            
            for(int i=0; i<8; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 || ny<0 || nx>=H || ny>=W) continue;
                if(arr[nx][ny]==-1 || arr[nx][ny]==9) continue;
                
                sand[nx][ny]++;
                if(visited[nx][ny]) continue;
                if(sand[nx][ny]>=arr[nx][ny]){
                    visited[nx][ny]=true;
                    q.push({nx, ny});
                }
            }
        }
        
        cnt++;
    }
    
    cout<<cnt;
}