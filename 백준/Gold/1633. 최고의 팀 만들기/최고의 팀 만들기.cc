#include <bits/stdc++.h>
using namespace std;

int A, B, dp[1001][16][16];
vector<pair<int, int>> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin>>A>>B){
        arr.push_back({A, B});
    }
    
    dp[0][1][0]=arr[0].first;
    dp[0][0][1]=arr[0].second;
    
    for(int i=1; i<arr.size(); i++){
        for(int j=0; j<=15; j++){
            for(int k=0; k<=15; k++){
                if(j+k>i+1) break;
                if(j>0) dp[i][j][k]=max({dp[i][j][k], dp[i-1][j][k], dp[i-1][j-1][k]+arr[i].first});
                if(k>0) dp[i][j][k]=max({dp[i][j][k], dp[i-1][j][k], dp[i-1][j][k-1]+arr[i].second});
            }
        }
    }
    
    cout<<dp[arr.size()-1][15][15];
}