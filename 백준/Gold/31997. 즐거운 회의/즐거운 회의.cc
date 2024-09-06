#include <iostream>
#include <vector>
using namespace std;

vector<int> come[200001], out[200001], adj[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, T;
    cin>>N>>M>>T;
    for(int i=1; i<=N; i++){
        int A, B;
        cin>>A>>B;
        come[A].push_back(i);
        out[B].push_back(i);
    }
    
    for(int i=0; i<M; i++){
        int C, D;
        cin>>C>>D;
        adj[C].push_back(D);
        adj[D].push_back(C);
    }
    
    vector<bool> join(N+1, false);
    int ans=0;
    
    // 시간이 흐름
    for(int i=0; i<T; i++){
        // i초에 나간 사람과 연관된 사람을 모두 join 해제 처리
        for(auto a: out[i]){
            join[a]=false;
            
            for(auto b: adj[a]){
                if(join[b]) {
                    ans--;
                }
            }
        }
        
        // i초에 들어온 사람과 연관된 사람을 모두 join 처리
        for(auto a: come[i]){
            join[a]=true;
            
            for(auto b: adj[a]){
                if(join[b]){
                    ans++;
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}