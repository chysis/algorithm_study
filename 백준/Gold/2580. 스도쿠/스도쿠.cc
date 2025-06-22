#include <bits/stdc++.h>
using namespace std;

int arr[10][10];
bool row[10][10], col[10][10], box[10][10];

int getBox(int x, int y){
    return (x/3)*3+(y/3);
}

void solve(int cnt){
    if(cnt==81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }
    
    int x=cnt/9;
    int y=cnt%9;
    if(arr[x][y]!=0) solve(cnt+1);
    else{
        for(int i=1; i<=9; i++){
            if(row[x][i] || col[y][i] || box[getBox(x, y)][i]) continue;
            arr[x][y]=i;
            row[x][i]=col[y][i]=box[getBox(x, y)][i]=true;
            solve(cnt+1);
            arr[x][y]=0;
            row[x][i]=col[y][i]=box[getBox(x, y)][i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>arr[i][j];
            if(arr[i][j]!=0) {
                row[i][arr[i][j]]=true;
                col[j][arr[i][j]]=true;
                box[getBox(i, j)][arr[i][j]]=true;
            }
        }
    }
    
    solve(0);
}