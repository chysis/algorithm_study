#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF (~0U>>2)
using namespace std;

int N, T, P, seatEnd[101]; // 자리마다 끝나는 시각 저장
pii resv[501];
string s, e;

bool comp(pii& a, pii& b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

void initSeat(){
    for(int i=1; i<=N; i++) seatEnd[i]=-1;
}

int whereToSeat(){
    int cnt=0;
    for(int i=1; i<=N; i++){
        if(seatEnd[i]!=-1) cnt++;
    }
    
    if(cnt==0) return 1; // 이용 중인 사람 없는 경우
    
    int dist[101];
    for(int i=1; i<=N; i++) dist[i]=INF;
    
    for(int i=1; i<=N; i++){
        if(seatEnd[i]!=-1) continue; // 빈 자리를 찾고
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            if(seatEnd[j]!=-1){
                dist[i]=min(dist[i], abs(j-i)); // 가장 가까이에 앉은 사람과의 거리 측정
            }
        }
    }
    
    int res, resVal=-1;
    for(int i=1; i<=N; i++){
        if(seatEnd[i]!=-1) continue;
        if(resVal<dist[i]){ // 그 중 가장 거리가 먼 자리 찾기
            resVal=dist[i];
            res=i;
        }
    }
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>T>>P;
    for(int i=0; i<T; i++){
        cin>>s>>e;
        int sh=stoi(s.substr(0, 2));
        int sm=stoi(s.substr(2));
        int eh=stoi(e.substr(0, 2));
        int em=stoi(e.substr(2));
        resv[i]={sh*60+sm, eh*60+em};
    }
    
    initSeat();
    sort(resv, resv+T, comp);
    
    int occupied=0;
    for(int i=0; i<T; i++){
        for(int j=1; j<=N; j++){
            if(seatEnd[j]<=resv[i].first) seatEnd[j]=-1;
        }
        int seat=whereToSeat();
        seatEnd[seat]=resv[i].second;
        if(seat==P) occupied+=resv[i].second-resv[i].first;
    }
    
    cout<<720-occupied;
}