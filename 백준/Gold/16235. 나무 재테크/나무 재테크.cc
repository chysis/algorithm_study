#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int arr[11][11]; // 겨울마다 추가되는 양분
int energy[11][11]; // 남은 양분
vector<int> map[11][11]; // 나이, 생존여부

int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M>>K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>arr[i][j];
            energy[i][j]=5;
        }
    }
    
    for(int i=0; i<M; i++){
        int X, Y, Z;
        cin>>X>>Y>>Z;
        map[X][Y].push_back(Z);
    }
    
    while(K--){
        // 봄, 여름
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                sort(map[i][j].begin(), map[i][j].end());
            }
        }
        
        
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                vector<int> temp;
                int store=0;
                
                for(int k=0; k<map[i][j].size(); k++){
                    if(map[i][j][k]<=energy[i][j]){
                        energy[i][j]-=map[i][j][k];
                        map[i][j][k]++;
                        temp.push_back(map[i][j][k]);
                    }else{
                        store+=map[i][j][k]/2;
                    }
                }
                
                map[i][j]=temp;
                energy[i][j]+=store;
            }
        }
        
        // 가을
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                for(int k=0; k<map[i][j].size(); k++){
                    if(map[i][j][k]%5==0){
                        for(int a=0; a<8; a++){
                            int nx=i+dx[a];
                            int ny=j+dy[a];
                            
                            if(nx<1 || ny<1 || nx>N || ny>N) continue;
                            map[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
        
        // 겨울
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                energy[i][j]+=arr[i][j];
            }
        }
    }
    
    int ans=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            ans+=map[i][j].size();
        }
    }
    
    cout<<ans;
}