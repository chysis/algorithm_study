#include <iostream>
#include <algorithm>
#include <memory.h>

#define INF 987654321
using namespace std;

int N, K, arr[200001], ans=INF;
bool visited[200001];
int s, e;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    s=1, e=N;
    
    while(s<=e){
        int m=(s+e)/2;
        
        int cnt=0, cur=N;
        bool flag=true;
        
        while(true){
            if(cur<=1 || cnt>K) break;
            if(visited[cur]) {
                flag=false;
                break;
            }
            
            visited[cur]=true;

            if(arr[cur]){
                cur-=m;
                cnt++;
            } else{
                cur++;
            }
        }
        
        if(cnt>K || !flag) s=m+1;
        else{
            ans=min(ans, m);
            e=m-1;
        }
        
        memset(visited, false, sizeof(visited));
    }
    
    cout<<ans;
}