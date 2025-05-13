#include <bits/stdc++.h>
using namespace std;

int N, K, arr[1000001], temp=0, ans=0;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++) cin>>arr[i];
    for(int i=0; i<N; i++){
        if(arr[i]%2==0) temp++;
        else{
            v.push_back(temp);
            temp=0;
        }
    }
    v.push_back(temp);
    
    if(K>=v.size()-1){
        for(int i=0; i<v.size(); i++) ans+=v[i];
        cout<<ans;
        return 0;
    }
    
    int sum=0, s=0, e=K;
    for(int i=s; i<=e; i++) sum+=v[i];
    ans=max(ans, sum);
    
    while(e<v.size()){
        sum-=v[s];
        s++, e++;
        sum+=v[e];
        ans=max(ans, sum);
    }
    
    cout<<ans;
}