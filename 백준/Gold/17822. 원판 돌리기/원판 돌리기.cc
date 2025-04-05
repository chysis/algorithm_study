#include <bits/stdc++.h>
using namespace std;

int N, M, T, arr[51][51];

void rotate(int num, int dir, int amount){
    for(int i=num; i<=N; i+=num){
        //copy array
        int temp[51];
        for(int j=1; j<=M; j++){
            temp[j]=arr[i][j];
        }
        
        // rotate
        for(int j=1; j<=M; j++){
            int newPos=j+M;
            if(dir==0) newPos+=amount;
            else newPos-=amount;
            
            newPos%=M;
            if(newPos==0) newPos=M;
            
            arr[i][newPos]=temp[j];
        }
    }
}

void removeDuplicate(){
    vector<pair<int, int>> v;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(arr[i][j]==-1) continue;
            
            if(i==1){
                if(arr[i][j]==arr[i+1][j]){
                    v.push_back({i, j});
                    v.push_back({i+1, j});
                }
                
                int prev=j-1>0 ? j-1 : M;
                int next=j+1>M ? 1 : j+1;
                if(arr[i][j]==arr[i][prev]){
                    v.push_back({i, j});
                    v.push_back({i, prev});
                }
                if(arr[i][j]==arr[i][next]){
                    v.push_back({i, j});
                    v.push_back({i, next});
                }
            } else if(i==N){
                if(arr[i][j]==arr[i-1][j]){
                    v.push_back({i, j});
                    v.push_back({i-1, j});
                }
                
                int prev=j-1>0 ? j-1 : M;
                int next=j+1>M ? 1 : j+1;
                if(arr[i][j]==arr[i][prev]){
                    v.push_back({i, j});
                    v.push_back({i, prev});
                }
                if(arr[i][j]==arr[i][next]){
                    v.push_back({i, j});
                    v.push_back({i, next});
                }
            } else{
                if(arr[i][j]==arr[i+1][j]){
                    v.push_back({i, j});
                    v.push_back({i+1, j});
                }
                if(arr[i][j]==arr[i-1][j]){
                    v.push_back({i, j});
                    v.push_back({i-1, j});
                }
                
                int prev=j-1>0 ? j-1 : M;
                int next=j+1>M ? 1 : j+1;
                if(arr[i][j]==arr[i][prev]){
                    v.push_back({i, j});
                    v.push_back({i, prev});
                }
                if(arr[i][j]==arr[i][next]){
                    v.push_back({i, j});
                    v.push_back({i, next});
                }
            }
        }
    }
    
    if(v.size()==0){
        double avg=0.0, cnt=0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(arr[i][j]==-1) continue;
                avg+=(double)arr[i][j];
                cnt++;
            }
        }
        
        avg/=cnt;
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(arr[i][j]==-1) continue;
                
                if(arr[i][j]>avg) arr[i][j]--;
                else if(arr[i][j]<avg) arr[i][j]++;
            }
        }
    } else{
        for(auto a: v){
            arr[a.first][a.second]=-1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>T;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<T; i++){
        int X, D, K;
        cin>>X>>D>>K;
        rotate(X, D, K);
        removeDuplicate();
    }
    
    int ans=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(arr[i][j]==-1) continue;
            ans+=arr[i][j];
        }
    }
    
    cout<<ans;
}