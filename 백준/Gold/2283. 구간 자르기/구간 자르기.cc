#include <iostream>
#include <algorithm>

#define INF (~0U>>2)
using namespace std;

pair<int, int> arr[1001];
int delta[1000010], sum[1000010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K, mn=INF, mx=-1;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        int S, E;
        cin>>S>>E;
        mn=min(mn, S);
        mx=max(mx, E);
        arr[i]={S, E};
    }
    
    sort(arr, arr+N);
    
    for(int i=0; i<N; i++){
        delta[arr[i].first+1]++;
        delta[arr[i].second+1]--;
    }
    
    int temp=0;
    for(int i=mn; i<=mx; i++){
        temp+=delta[i];
        delta[i]=temp;
    }
    
    sum[mn]=delta[mn];
    for(int i=mn+1; i<=mx; i++){
        sum[i]=sum[i-1]+delta[i];
    }
    
    if(sum[mx]<K){
        cout<<0<<" "<<0;
        return 0;
    }
    
    int s=0, e=0;
    pair<int, int> ans={INF, INF};
    bool flag=false;
    while(e<=mx){
        int diff=sum[e]-sum[s];
        
        if(diff<K) e++;
        else if(diff>K) s++;
        else{
            cout<<s<<" "<<e;
            flag=true;
            break;
        }
    }
    
    if(!flag) cout<<0<<" "<<0;
}