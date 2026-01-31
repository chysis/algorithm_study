#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

struct Team{
    int popul=0;
    int score_sum=0;
    vector<int> scores;
};

int T, N, arr[1001], team_count=0;
Team team_info[201];

void init(){
    for(int i=1; i<=200; i++){
        team_info[i].popul=0;
        team_info[i].score_sum=0;
        team_info[i].scores.clear();
    }
    team_count=0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        init();
        cin>>N;
        for(int i=0; i<N; i++) cin>>arr[i];
        
        // 팀마다 참가 인원 계산
        for(int i=0; i<N; i++){
            team_count=max(team_count, arr[i]);
            team_info[arr[i]].popul++;
        }
        
        // 점수 매기기
        int cur=1;
        for(int i=0; i<N; i++){
            if(team_info[arr[i]].popul==6){
                team_info[arr[i]].scores.push_back(cur);
                if(team_info[arr[i]].scores.size()<=4){
                    team_info[arr[i]].score_sum+=cur;
                }
                cur++;
            }
        }
        
        // 우승팀 가리기
        int win_team=-1, win_score=INF;
        for(int i=1; i<=team_count; i++){
            if(team_info[i].popul==6){
                if(win_score>team_info[i].score_sum){
                    win_score=team_info[i].score_sum;
                    win_team=i;
                }
                else if(win_score==team_info[i].score_sum){
                    // 점수 합이 같으면 5번째 선수 비교
                    if(team_info[win_team].scores[4]>team_info[i].scores[4]){
                        win_score=team_info[i].score_sum;
                        win_team=i;
                    }
                }
            }
        }
        
        cout<<win_team<<"\n";
    }
}