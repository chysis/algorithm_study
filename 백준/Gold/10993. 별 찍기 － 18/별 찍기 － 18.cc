#include <iostream>
using namespace std;

int N;
char arr[1024][2046];

void solve(int cnt, int x, int y){
    arr[x][y]='*';
    if(cnt==N+1) return;
    
    int height=(1<<cnt)-1;
    int width=2*height-1;
    
    if(cnt%2==0){
        // 역삼각형
        int tempX=x+(height/2);
        arr[tempX][y]='*';
        
        for(int i=1; i<height; i++){
            arr[tempX-i][y-i]='*';
            arr[tempX-i][y+i]='*';
        }
        
        tempX=x-(height/2);
        arr[tempX][y]='*';
        
        for(int i=1; i<width/2; i++){
            arr[tempX][y-i]='*';
            arr[tempX][y+i]='*';
        }
        
        solve(cnt+1, tempX, y);
    }
    else{
        // 정삼각형
        int tempX=x-(height/2);
        arr[tempX][y]='*';
        
        for(int i=1; i<height; i++){
            arr[tempX+i][y-i]='*';
            arr[tempX+i][y+i]='*';
        }
        
        tempX=x+(height/2);
        arr[tempX][y]='*';
        
        for(int i=1; i<width/2; i++){
            arr[tempX][y-i]='*';
            arr[tempX][y+i]='*';
        }
        
        solve(cnt+1, tempX, y);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    cin>>N;
    
    int height=(1<<N)-1;
    int width=2*height-1;

    for(int i=1; i<=height; i++){
        for(int j=1; j<=width; j++){
            arr[i][j]=' ';
        }
    }
    
    int startX=height/2+1;
    int startY=width/2+1;
    
    int offset[10]={0, 0, 1, -2, 5, -10, 21, -42, 85, -170};

    solve(1, startX+offset[N-1], startY);
    
    if(N%2==0){
        for(int i=1; i<=height; i++){
            for(int j=1; j<=width-(i-1); j++){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
    }
    else{
        for(int i=1; i<=height; i++){
            for(int j=1; j<=width-(height-i); j++){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
    }
}