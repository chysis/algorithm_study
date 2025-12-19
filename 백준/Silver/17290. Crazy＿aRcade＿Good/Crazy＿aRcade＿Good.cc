#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int R, C, ans=INF;
char arr[11][11];
vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C;
    R--; C--;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='o'){
                v.push_back({i, j});
            }
        }
    }
    
    for(auto cur: v){
        for(int i=0; i<10; i++){
            arr[cur.first][i]='o';
            arr[i][cur.second]='o';
        }
    }
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(arr[i][j]=='x'){
                ans=min(ans, abs(i-R)+abs(j-C));
            }
        }
    }
    
    cout<<ans;
}