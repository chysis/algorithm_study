#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> arr[1001];
int score[1001];

bool comp(pair<int, int>& a, pair<int, int>& b){
    if(a.second!=b.second) return a.second>b.second;
    else return a.first<b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, maxDate=-1;
    cin>>N;
    for(int i=0; i<N; i++){
        int D, W;
        cin>>D>>W;
        maxDate=max(maxDate, D);
        arr[i]={D, W};
    }
    
    sort(arr, arr+N, comp);
    
    for(int i=0; i<N; i++){
        int date=arr[i].first;
        if(score[date]==0) score[date]=arr[i].second;
        else{
            for(int j=date; j>=1; j--){
                if(score[j]==0){
                    score[j]=arr[i].second;
                    break;
                }
            }
        }
    }
    
    int ans=0;
    for(int i=1; i<=maxDate; i++){
        ans+=score[i];
    }
    
    cout<<ans;
}