#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, v[51];
priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    if(N==1){
        cout<<0;
        return 0;
    }
    
    for(int i=1; i<=N; i++){
        cin>>v[i];
        if(i>1) pq.push(v[i]);
    }
    
    int ans=0;
    while(v[1]<=pq.top()){
        v[1]++;
        ans++;
        pq.push(pq.top()-1);
        pq.pop();
    }
    
    cout<<ans;
}