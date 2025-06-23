#include <bits/stdc++.h>
using namespace std;

int N, arr[1025][1025];

int solve(int x, int y, int s){
    if(s==2){
        int temp[4]={arr[x][y], arr[x+1][y], arr[x][y+1], arr[x+1][y+1]};
        sort(temp, temp+4);
        return temp[1];
    }
    
    int temp[4]={solve(x, y, s/2), solve(x+s/2, y, s/2), solve(x, y+s/2, s/2), solve(x+s/2, y+s/2, s/2)};
    sort(temp, temp+4);
    return temp[1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    
    if(N==1){
        cout<<arr[0][0];
        return 0;
    }
    
    cout<<solve(0, 0, N);
}