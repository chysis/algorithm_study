#include <iostream>
#include <algorithm>
using namespace std;

int N, M, minOffset, limit[51], weight[10001], bound_cnt[51];

bool isDone(){
    for(int i=N; i>=minOffset; i--){
        if(bound_cnt[i]>0){
            int sum=0;
            for(int j=i; j<=N; j++){
                sum+=bound_cnt[j];
            }
            if(sum>0) return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    int maxLimit=-1;
    for(int i=1; i<=N; i++){
        cin>>limit[i];
        maxLimit=max(maxLimit, limit[i]);
    }
    limit[0]=0;
    
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>weight[i];
        if(weight[i]>maxLimit){
            cout<<-1;
            return 0;
        }
    }
    
    sort(limit, limit+N+1);
    sort(weight, weight+M);
    
    for(int i=1; i<=N; i++){
        bound_cnt[i]=upper_bound(weight, weight+M, limit[i])-lower_bound(weight, weight+M, limit[i-1]+1);
    }
    
    minOffset=lower_bound(limit, limit+N+1, weight[0])-limit;
    
    int cnt=0;
    while(true){
        if(isDone()) break;
        
        for(int i=1; i<=N; i++){
            bound_cnt[i]--;
        }
        cnt++;
    }
    
    cout<<cnt;
}