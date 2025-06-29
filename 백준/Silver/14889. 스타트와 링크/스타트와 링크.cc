#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, arr[21][21], sel[21], total=0, ans=INF;
bool visited[21];

void solve(int cnt, int prev){
    if(cnt==N/2){
        int temp=0;
        for(int i=0; i<N/2; i++){
            for(int j=i+1; j<N/2; j++){
                temp+=arr[sel[i]][sel[j]];
                temp+=arr[sel[j]][sel[i]];
            }
        }
        
        vector<int> remain;
        for(int i=0; i<N; i++){
            if(find(sel, sel+N/2, i)==sel+N/2){
                remain.push_back(i);
            }
        }
        
        int temp2=0;
        for(int i=0; i<N/2; i++){
            for(int j=i+1; j<N/2; j++){
                temp2+=arr[remain[i]][remain[j]];
                temp2+=arr[remain[j]][remain[i]];
            }
        }
        ans=min(ans, abs(temp-temp2));
        return;
    }
    
    for(int i=prev; i<N; i++){
        if(!visited[i]){
            visited[i]=true;
            sel[cnt]=i;
            solve(cnt+1, i);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            total+=arr[i][j];
        }
    }
    
    solve(0, 0);
    cout<<ans;
}