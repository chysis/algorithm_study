#include <bits/stdc++.h>
using namespace std;

int N, M, A, B, rulemap[101], yjmap[101];
pair<int, int> rule[101], yj[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>A>>B;
        rule[i]={A, B};
    }
    for(int i=0; i<M; i++){
        cin>>A>>B;
        yj[i]={A, B};
    }
    
    int prev=1;
    for(int i=0; i<N; i++){
        for(int j=prev; j<prev+rule[i].first; j++){
            rulemap[j]=rule[i].second;
        }
        prev+=rule[i].first;
    }
    
    prev=1;
    for(int i=0; i<M; i++){
        for(int j=prev; j<prev+yj[i].first; j++){
            yjmap[j]=yj[i].second;
        }
        prev+=yj[i].first;
    }
    
    int ans=0;
    for(int i=1; i<=100; i++){
        ans=max(ans, yjmap[i]-rulemap[i]);
    }

    cout<<ans;
}