#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int R, C, jx, jy;
int dx[10]={-1, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[10]={-1, -1, 0, 1, -1, 0, 1, -1, 0, 1};
char arr[101][101];
string S;
vector<pair<int, int>> adu;

void moveAdu(){
    for(auto& a: adu){
        int rx=a.first;
        int ry=a.second;
        
        int idx=-1, val=INF;
        for(int i=1; i<=9; i++){
            if(i==5) continue;
            int newRx=rx+dx[i];
            int newRy=ry+dy[i];
            if(newRx<0 || newRy<0 || newRx>=R || newRy>=C) continue;
            
            int dist=abs(jx-newRx)+abs(jy-newRy);
            if(val>dist){
                val=dist;
                idx=i;
            }
        }

        a.first=rx+dx[idx];
        a.second=ry+dy[idx];
    }
}

bool isOver(){
    for(auto a: adu){
        if(a.first==jx && a.second==jy) return true;
    }
    
    return false;
}

void findExplosion(){
    vector<int> temp[101][101];
    vector<bool> isExplode(adu.size());
    
    for(int i=0; i<adu.size(); i++){
        temp[adu[i].first][adu[i].second].push_back(i);
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(temp[i][j].size()>=2){
                for(int k=temp[i][j].size()-1; k>=0; k--){
                    isExplode[temp[i][j][k]]=true;
                }
            }
        }
    }
    
    for(int i=adu.size()-1; i>=0; i--){
        if(isExplode[i]) adu.erase(adu.begin()+i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='I') jx=i, jy=j;
            else if(arr[i][j]=='R') adu.push_back({i, j});
        }
    }
    cin>>S;
    
    for(int i=0; i<S.length(); i++){
        jx+=dx[S[i]-'0'];
        jy+=dy[S[i]-'0'];
        if(isOver()){
            cout<<"kraj "<<i+1;
            return 0;
        }

        moveAdu();
        if(isOver()){
            cout<<"kraj "<<i+1;
            return 0;
        }
        findExplosion();
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            arr[i][j]='.';
        }
    }
    
    arr[jx][jy]='I';
    for(auto a: adu){
        arr[a.first][a.second]='R';
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}