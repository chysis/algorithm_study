#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, s=0, map[101][101];
vector<pair<int, int>> v;
bool done[10001];

bool comp(pair<int, int>& a, pair<int, int>& b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(map[i][j]==1) {
                v.push_back({i, j});
                s++;
            }
        }
    }
    
    sort(v.begin(), v.end(), comp);
    
    int ans=0;
    while(true){
        int x=-1, y=-1;
        for(int i=0; i<s; i++){
            if(!done[i]){
                if(v[i].first>=x && v[i].second>=y){
                    x=v[i].first, y=v[i].second;
                    done[i]=true;
                }
            }
        }
        if(x==-1 && y==-1) break;
        ans++;
    }
    
    cout<<ans;
}