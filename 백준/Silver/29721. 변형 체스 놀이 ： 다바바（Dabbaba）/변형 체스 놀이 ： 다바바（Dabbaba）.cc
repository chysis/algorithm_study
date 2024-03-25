#include <iostream>
#include <set>
using namespace std;

int dx[4]={-2, 2, 0, 0};
int dy[4]={0, 0, -2, 2};

pair<int, int> arr[100001];
set<pair<int, int>> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    for(int i=0; i<K; i++){
        int X, Y;
        cin>>X>>Y;
        arr[i]={X, Y};
        s.insert({X, Y});
    }
    
    for(int i=0; i<K; i++){
        for(int j=0; j<4; j++){
            int nx=arr[i].first+dx[j];
            int ny=arr[i].second+dy[j];
            if(nx<1 || ny<1 || nx>N || ny>N) continue;
            if(s.find({nx, ny})!=s.end()) continue;
            s.insert({nx, ny});
        }
    }
    
    cout<<s.size()-K;
}