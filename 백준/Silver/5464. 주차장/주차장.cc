#include <bits/stdc++.h>
using namespace std;

int N, M, X, fee[101], weight[2001], car[101], ans=0;
queue<int> q;

int cntEmpty(){
    int temp=0;
    for(int i=1; i<=N; i++){
        if(car[i]==-1) temp++;
    }
    return temp;
}

int minParkNum(){
    for(int i=1; i<=N; i++){
        if(car[i]==-1) return i;
    }
    return -1;
}

int findLoc(int carNum){
    for(int i=1; i<=N; i++){
        if(car[i]==carNum) return i;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin>>N>>M;
    for(int i=1; i<=N; i++) car[i]=-1;
    for(int i=1; i<=N; i++) cin>>fee[i];
    for(int i=1; i<=M; i++) cin>>weight[i];
    for(int i=0; i<2*M; i++){
        cin>>X;
        if(X>0){
            int cnt=cntEmpty();
            if(cnt>=1){
                int loc=minParkNum();
                car[loc]=X;
                ans+=fee[loc]*weight[X];
            }else{
                q.push(X);
            }
        }else if(X<0){
            int carLoc=findLoc(-X);
            car[carLoc]=-1;
            
            if(!q.empty()){
                int cnt=cntEmpty();
                if(cnt>=1){
                    int loc=minParkNum();
                    car[loc]=q.front();
                    ans+=fee[loc]*weight[q.front()];
                }
                q.pop();
            }
        }
    }
    cout<<ans;
}