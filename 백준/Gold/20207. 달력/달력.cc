#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, S, E, minVal=INF, maxVal=0, h[367];
pair<int, int> arr[1001];

bool comp(pair<int, int>& a, pair<int, int>& b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second>b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>S>>E;
        minVal=min({minVal, S});
        maxVal=max({maxVal, E});
        arr[i]={S, E};
    }
    
    sort(arr, arr+N, comp);
    
    for(int i=0; i<N; i++){
        for(int j=arr[i].first; j<=arr[i].second; j++){
            h[j]++;
        }
    }
    
    int ans=0, tempLen=0, tempVal=0;
    for(int i=minVal; i<=maxVal+1; i++){
        if(h[i]!=0){
            tempLen++;
            tempVal=max(tempVal, h[i]);
        } else{
            ans+=(tempLen*tempVal);
            tempLen=tempVal=0;
        }
    }
    cout<<ans;
}