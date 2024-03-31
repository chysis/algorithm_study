#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

bool isPrime[10001];
bool visited[10001];
int digit[4];
queue<pair<int, int>> q;

void primeNumber(){
    for(int i=0; i<=10000; i++){
        isPrime[i]=true;    
    }
    
    for(int i=2; i*i<=10000; i++){
        if(isPrime[i]){
            for(int j=i*2; j<=10000; j+=i){
                isPrime[j]=false;
            }
        }
    }
}

int bfs(int target){
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        
        if(cur.first==target) return cur.second;
        
        for(int i=3; cur.first>0; i--){
            digit[i]=cur.first%10;
            cur.first/=10;
        }
        
        for(int i=0; i<4; i++){
            for(int j=0; j<=9; j++){
                int temp=digit[i];
                if(i==0 && j==0) continue;
                digit[i]=j;
                
                int num=digit[0]*1000+digit[1]*100+digit[2]*10+digit[3];
                if(!visited[num] && isPrime[num]){
                    q.push({num, cur.second+1});
                    visited[num]=true;
                }
                
                digit[i]=temp;
            }
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    primeNumber();
    
    int T;
    cin>>T;
    while(T--){
        int start, target;
        cin>>start>>target;
        
        if(start==target){
            cout<<0<<"\n";
            continue;
        }
        
        q.push({start, 0});
        visited[start]=true;
        
        int res=bfs(target);
        if(res==-1) cout<<"Impossible\n";
        else cout<<res<<"\n";
        
        memset(visited, false, sizeof(visited));
        q={};
    }
}