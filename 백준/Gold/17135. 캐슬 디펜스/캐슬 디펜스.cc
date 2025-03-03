#include <bits/stdc++.h>
using namespace std;

int N, M, D, arr[17][17], ans=0;
vector<pair<int, int>> enemy;
pair<int, int> archer[4];
bool visited[17];

int playGame(){
    vector<pair<int, int>> tempEnemy;
    for(int i=0; i<enemy.size(); i++){
        tempEnemy.push_back(enemy[i]);
    }
    
    int tempCnt=0;
    
    while(!tempEnemy.empty()){
        vector<int> dieIndex; // 사라질 적 인덱스
        
        for(int i=0; i<3; i++){
            int targetIndex=-1, targetDist=D+1;
            for(int j=0; j<tempEnemy.size(); j++){
                int dist=abs(archer[i].first-tempEnemy[j].first)+abs(archer[i].second-tempEnemy[j].second);
                if(targetDist>dist && dist<=D){
                    targetDist=dist;
                    targetIndex=j;
                }
            }
            
            if(targetIndex!=-1){
                if(find(dieIndex.begin(), dieIndex.end(), targetIndex)==dieIndex.end()){
                    dieIndex.push_back(targetIndex);
                }
            }
        }
        
        sort(dieIndex.begin(), dieIndex.end(), greater<int>());
        
        // 공격받은 적 제거 
        for(int i=0; i<dieIndex.size(); i++){
            tempEnemy.erase(tempEnemy.begin()+dieIndex[i]);
            tempCnt++;
        }
        
        dieIndex.clear();
        // 적 한 칸씩 아래로 이동
        for(int i=0; i<tempEnemy.size(); i++){
            if(tempEnemy[i].first==N-1) dieIndex.push_back(i);
            else tempEnemy[i].first++;
        }
        
        sort(dieIndex.begin(), dieIndex.end(), greater<int>());
        
        // arr을 벗어나는 적 제거
        for(int i=0; i<dieIndex.size(); i++){
            tempEnemy.erase(tempEnemy.begin()+dieIndex[i]);
        }
    }
    
    return tempCnt;
}

void solve(int cnt, int prev){
    if(cnt==3){
        ans=max(ans, playGame());
        return;
    }
    
    for(int i=prev; i<M; i++){
        if(!visited[i]){
            archer[cnt]={N, i};
            visited[i]=true;
            solve(cnt+1, i);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>D;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(arr[j][i]==1) enemy.push_back({j, i});
        }
    }

    solve(0, 0);
    cout<<ans;
}