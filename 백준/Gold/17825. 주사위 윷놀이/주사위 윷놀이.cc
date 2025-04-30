#include <bits/stdc++.h>
using namespace std;

int arr[11], sel[11], ans=0;
vector<int> board[4];

void makeBoard(){ // 44는 도착
    board[0]={0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 44, 44, 44, 44, 44};
    board[1]={10, 13, 16, 19, 25, 30, 35, 40, 44, 44, 44, 44, 44};
    board[2]={20, 22, 24, 25, 30, 35, 40, 44, 44, 44, 44, 44};
    board[3]={30, 28, 27, 26, 25, 30, 35, 40, 44, 44, 44, 44, 44};
}

void solve(){
    int temp=0;
    pair<int, int> pos[4]; // 말 위치
    
    for(int i=0; i<10; i++){
        int curMal=sel[i];
        int num=arr[i];
        int& x=pos[curMal].first;
        int& y=pos[curMal].second;

        if(board[x][y]==44) break; // 이미 도착한 말을 또 움직이는 경우
        if(board[x][y+num]==44){  // 도착하면 점수 없음
            y+=num;
            continue;
        }
        
        if(x==0 && (board[x][y+num]==10 || board[x][y+num]==20 || board[x][y+num]==30)){
            x=board[x][y+num]/10; // 값이 10, 20, 30이라고 전부 지름길은 아님
            y=0;
        } else{
            y+=num;
        }
        
        // 다른 말이 해당 위치에 있는지 확인
        for(int j=0; j<4; j++){
            if(j==curMal) continue;
            // 인덱스가 동일한 경우
            if(pos[j].first==x && pos[j].second==y){
                return;
            }
            // 둘레길, 지름길 포함 40에서 겹치는 경우
            if(board[x][y]==40 && board[pos[j].first][pos[j].second]==40){
                return;
            }
            // 지름길에서 합쳐지는 부분(25, 30, 35) 겹치는 경우
            if(x>0 && y>0 && pos[j].first>0 && pos[j].second>0 && board[pos[j].first][pos[j].second]==board[x][y]){
                return;
            }
        }
        
        temp+=board[x][y];
    }
    
    ans=max(ans, temp);
}

void perm(int cnt){
    if(cnt==10){
        solve();
        return;
    }
    
    for(int i=0; i<4; i++){
        sel[cnt]=i;
        perm(cnt+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    for(int i=0; i<10; i++){
       cin>>arr[i];
    }
   
    makeBoard();
    perm(0);

    cout<<ans;
}