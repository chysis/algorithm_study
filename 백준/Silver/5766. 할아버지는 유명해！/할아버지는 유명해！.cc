#include <bits/stdc++.h>
using namespace std;

int N, M, num, cnt[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin>>N>>M){
        if(N==0 && M==0) break;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>num;
                cnt[num]++;
            }
        }
        
        vector<int> v;
        for(int i=1; i<=10000; i++){
            if(cnt[i]>0) v.push_back(cnt[i]);
        }
        sort(v.begin(), v.end());
        int maxVal=v[v.size()-2];
        
        vector<int> t;
        for(int i=1; i<=10000; i++){
            if(cnt[i]==maxVal) t.push_back(i);
        }
        sort(t.begin(), t.end());
        
        for(auto a: t) cout<<a<<" ";
        cout<<"\n";
        memset(cnt, 0, sizeof(cnt));
    }
}