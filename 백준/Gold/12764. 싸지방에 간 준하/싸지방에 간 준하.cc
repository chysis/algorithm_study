#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[100001];

vector<int> seat_cnt; // 자리별 이용자 수(size가 곧 컴퓨터 대수)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied; // 끝나는 시각, 인덱스
priority_queue<int, vector<int>, greater<int>> available; // 인덱스

bool comp(pair<int, int>& a, pair<int, int>& b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    sort(arr, arr+N, comp);
    
    for(int i=0; i<N; i++){
        int start_time=arr[i].first;
        int end_time=arr[i].second;
        
        // 다 사용한 자리 치우기
        while(!occupied.empty() && occupied.top().first<=start_time){
            int idx=occupied.top().second;
            occupied.pop();
            available.push(idx);
        }
        
        // 앉기
        int where_to_seat;
        if(!available.empty()){
            where_to_seat=available.top();
            available.pop();
        }else{
            where_to_seat=seat_cnt.size();
            seat_cnt.push_back(0); // 초기화
        }
        
        seat_cnt[where_to_seat]++;
        
        occupied.push({end_time, where_to_seat});
        
    }
    
    cout<<seat_cnt.size()<<"\n";
    for(auto a: seat_cnt) cout<<a<<" ";
}