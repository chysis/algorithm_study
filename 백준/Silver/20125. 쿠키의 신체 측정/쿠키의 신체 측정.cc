#include <iostream>
using namespace std;

char arr[1002][1002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>arr[i][j];
        }
    }
    
    int cx, cy;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]=='*'){
                if(arr[i-1][j]=='*' && arr[i][j-1]=='*' && arr[i][j+1]=='*' && arr[i+1][j]=='*'){
                    cx=i, cy=j;
                }
            }
        }
    }
    cout<<cx<<" "<<cy<<"\n";
    
    int cnt=0, x=cx, y=cy;
    while(true){
        y-=1;
        if(arr[x][y]=='*') cnt++;
        else break;
    }
    cout<<cnt<<" ";
    
    cnt=0, x=cx, y=cy;
    while(true){
        y+=1;
        if(arr[x][y]=='*') cnt++;
        else break;
    }
    cout<<cnt<<" ";
    
    int dx, dy;
    cnt=0, x=cx, y=cy;
    while(true){
        x+=1;
        if(arr[x][y]=='*') cnt++;
        else {
            dx=x, dy=y;
            break;
        }
    }
    cout<<cnt<<" ";
    
    cnt=1, x=dx, y=dy-1;
    while(true){
        x+=1;
        if(arr[x][y]=='*') cnt++;
        else {
            break;
        }
    }
    cout<<cnt<<" ";
    
    cnt=1, x=dx, y=dy+1;
    while(true){
        x+=1;
        if(arr[x][y]=='*') cnt++;
        else {
            break;
        }
    }
    cout<<cnt;
}