#include <bits/stdc++.h>
using namespace std;

char c;
int num, arr[10], color[5];
vector<int> cnt[6], cntColor[6]; // i번 등장한 숫자 목록
pair<char, int> card[6];

bool isAdjNum(){
    return card[0].second+4==card[4].second
    && card[1].second+3==card[4].second
    && card[2].second+2==card[4].second
    && card[3].second+1==card[4].second;
}

bool comp(pair<char, int>& a, pair<char, int>& b){
    return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<5; i++){
        cin>>c>>num;
        card[i]={c, num};
    }
    
    sort(card, card+5, comp);
    
    for(int i=0; i<5; i++){
        arr[card[i].second]++;
        
        if(card[i].first=='R') color[0]++;
        else if(card[i].first=='G') color[1]++;
        else if(card[i].first=='B') color[2]++;
        else color[3]++;
    }
    
    for(int i=1; i<=9; i++){
        cnt[arr[i]].push_back(i);
    }
    
    for(int i=0; i<4; i++){
        cntColor[color[i]].push_back(i);
    }
    
    int ans;
    
    if(!cntColor[5].empty() && isAdjNum()){
        ans=card[4].second+900;
    } else if(!cnt[4].empty()){
        ans=cnt[4][0]+800;
    } else if(cnt[3].size()==1 && cnt[2].size()==1){
        ans=cnt[3][0]*10+cnt[2][0]+700;
    } else if(!cntColor[5].empty()){
        ans=card[4].second+600;
    } else if(isAdjNum()){
        ans=card[4].second+500;
    } else if(cnt[3].size()==1){
        ans=cnt[3][0]+400;
    } else if(cnt[2].size()==2){
        ans=max(cnt[2][0], cnt[2][1])*10+min(cnt[2][0], cnt[2][1])+300;
    } else if(cnt[2].size()==1){
        ans=cnt[2][0]+200;
    } else{
        ans=card[4].second+100;
    }
    
    cout<<ans;
}