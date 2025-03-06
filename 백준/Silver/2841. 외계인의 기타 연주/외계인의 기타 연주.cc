#include <bits/stdc++.h>
using namespace std;

int N, P, line, fret;
priority_queue<int> pq[7];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>P;
    
    int ans=0;
    for(int i=0; i<N; i++){
        cin>>line>>fret;
        while(true){
            if(pq[line].empty()){
                pq[line].push(fret);
                ans++;
                break;
            }
            
            if(pq[line].top()<fret){
                pq[line].push(fret);
                ans++;
                break;
            } else if(pq[line].top()>fret){
                pq[line].pop();
                ans++;
            } else{
                break;
            }
        }
    }
    
    cout<<ans;
}