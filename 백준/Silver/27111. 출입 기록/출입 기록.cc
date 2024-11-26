#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

bool visited[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, ans=0, mn=INF, mx=-1;
    cin>>N;
    for(int i=0; i<N; i++){
        int A, B;
        cin>>A>>B;
        mx=max(mx, A);
        mn=min(mn, A);
        
        if(B==1){
            if(visited[A]) ans++;
            else visited[A]=true;
        } else{
            if(!visited[A]) ans++;
            else visited[A]=false;
        }
    }
    
    for(int i=mn; i<=mx; i++){
        if(visited[i]) ans++;
    }
    
    cout<<ans;
}