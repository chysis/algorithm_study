#include <bits/stdc++.h>
using namespace std;

// 지우 -> 경희 -> 민호 순

int N, K, adj[10][10], hand[3][20], pos[3];
bool canWin=false;

// 지우의 이전 동작, 현재 동작, 1번 참가자, 2번 참가자, 비참가자, 승리 횟수
void solve(bool used[], int cur, int first, int second, int other, int win_cnt[]){
    if(canWin) return;
    if(win_cnt[0]>=K){
        canWin=true;
        return;
    }
    if(win_cnt[1]>=K || win_cnt[2]>=K) return;
    
    // pos를 초과한 경우
    if(first!=0 && pos[first]>=20) return;
    if(second!=0 && pos[second]>=20) return;
    
    // 참가자 손동작 확인
    int old_pos_first=pos[first];
    int old_pos_second=pos[second];
    
    int first_hand, second_hand;
    
    if(first==0) first_hand=cur;
    else first_hand=hand[first][pos[first]++];
    
    if(second==0) second_hand=cur;
    else second_hand=hand[second][pos[second]++];
    
    // 승리 계산
    int next_win_cnt[3]={win_cnt[0], win_cnt[1], win_cnt[2]};
    int winner, loser, res=adj[first_hand][second_hand];
    
    if(res==2){
        winner=first; loser=second;
    }else if(res==0){
        winner=second; loser=first;
    }else{
        winner=max(first, second);
        loser=(winner==first ? second : first);
    }
    
    next_win_cnt[winner]++;
    
    // 지우가 우승할 수 있지만 손동작을 다 사용한 경우, 다음 재귀로 넘어갈 수 없음
    // 다른 사람이 우승했더라도 게임 종료이므로 상태 복구 후 return 처리
    // next_win_cnt를 계산한 뒤에 다시 우승 판정 필요
    if(next_win_cnt[winner]>=K){
        if(winner==0) canWin=true;
        pos[first]=old_pos_first;
        pos[second]=old_pos_second;
        return;
    }
    
    // 지우가 다음 판에 참여하는 경우
    if(winner==0 || other==0){
        for(int i=1; i<=N; i++){
            if(used[i]) continue;
            used[i]=true;
            solve(used, i, winner, other, loser, next_win_cnt);
            used[i]=false;
            if(canWin) break;
        }
    }else{
        solve(used, cur, winner, other, loser, next_win_cnt);
    }
    
    // pos 이전 상태로 복구
    pos[first]=old_pos_first;
    pos[second]=old_pos_second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>adj[i][j];
        }
    }
    for(int i=0; i<20; i++) cin>>hand[1][i]; // 경희
    for(int i=0; i<20; i++) cin>>hand[2][i]; // 민호
    
    for(int i=1; i<=N; i++){
        if(canWin) break;
        memset(pos, 0, sizeof(pos)); // pos 초기화
        
        int win_cnt[3]={0, 0, 0};
        bool used[10];
        memset(used, false, sizeof(used));
        used[i]=true;
        solve(used, i, 0, 1, 2, win_cnt);
    }
    
    if(canWin) cout<<1;
    else cout<<0;
}