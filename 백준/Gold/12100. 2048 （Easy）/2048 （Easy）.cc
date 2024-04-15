#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

int N, ans=-1;
int board[21][21];
vvi v[6];

vvi moveBlock(int dir, vvi& v){
    vvi temp=v;
    bool done[21][21];
    
    // 블록 위로 밀기
    if(dir==0){
        for(int j=0; j<N; j++){
            int cnt=0;
            for(int i=0; i<N; i++){
                if(temp[i][j]==0) continue;
                int num=temp[i][j];
                temp[i][j]=0;
                
                if(temp[cnt][j]==0) temp[cnt][j]=num;
                else if(temp[cnt][j]==num) temp[cnt++][j]*=2;
                else temp[++cnt][j]=num;
            }
        }
    }
    // 블록 아래로 밀기
    else if(dir==1){
        for(int j=0; j<N; j++){
            int cnt=N-1;
            for(int i=N-1; i>=0; i--){
                if(temp[i][j]==0) continue;
                int num=temp[i][j];
                temp[i][j]=0;
                
                if(temp[cnt][j]==0) temp[cnt][j]=num;
                else if(temp[cnt][j]==num) temp[cnt--][j]*=2;
                else temp[--cnt][j]=num;
            }
        }
    }
    // 블록 왼쪽으로 밀기
    else if(dir==2){
        for(int i=0; i<N; i++){
            int cnt=0;
            for(int j=0; j<N; j++){
                if(temp[i][j]==0) continue;
                int num=temp[i][j];
                temp[i][j]=0;
                
                if(temp[i][cnt]==0) temp[i][cnt]=num;
                else if(temp[i][cnt]==num) temp[i][cnt++]*=2;
                else temp[i][++cnt]=num;
            }
        }    
    }
    // 블록 오른쪽으로 밀기
    else if(dir==3){
        for(int i=0; i<N; i++){
            int cnt=N-1;
            for(int j=N-1; j>=0; j--){
                if(temp[i][j]==0) continue;
                int num=temp[i][j];
                temp[i][j]=0;
                
                if(temp[i][cnt]==0) temp[i][cnt]=num;
                else if(temp[i][cnt]==num) temp[i][cnt--]*=2;
                else temp[i][--cnt]=num;
            }
        }
    }
    return temp;
}

int getMax(){
    int res=-1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(res<v[5][i][j]) res=v[5][i][j];
        }
    }
    return res;
}

void solve(int cnt){
    if(cnt==6){
        int temp=getMax();
        if(temp>ans) {
            ans=temp;
        }
        return;
    }
    
    for(int i=0; i<4; i++){
        v[cnt]=moveBlock(i, v[cnt-1]);
        solve(cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i=0; i<N; i++){
        vi temp;
        for(int j=0; j<N; j++){
            cin>>board[i][j];
            temp.push_back(board[i][j]);
        }
        v[0].push_back(temp);
    }
    
    solve(1);
    cout<<ans;
}