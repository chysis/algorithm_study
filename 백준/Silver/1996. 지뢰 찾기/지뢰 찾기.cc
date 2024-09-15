#include <iostream>
using namespace std;

int map[1001][1001];
char ans[1001][1001];
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c;
            cin>>c;
            if(c=='.') map[i][j]=0;
            else map[i][j]=c-'0';
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]!=0) ans[i][j]='*';
            else{
                int temp=0;
                for(int k=0; k<8; k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x<0 || y<0 || x>=N || y>=N) continue;
                    temp+=map[x][y];
                }
                
                if(temp>=10) ans[i][j]='M';
                else ans[i][j]=temp+'0';
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
}