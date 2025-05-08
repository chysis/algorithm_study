#include <bits/stdc++.h>
using namespace std;

int N, num, ans=0;
vector<int> m, p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        if(num==1) {
            ans+=1;
            continue;
        }
        
        if(num<=0) m.push_back(num);
        else p.push_back(num);
    }
    
    sort(m.begin(), m.end());
    sort(p.begin(), p.end(), greater<int>());
    
    for(int i=0; i<p.size()/2; i++){
        ans+=(p[2*i]*p[2*i+1]);
    }
    if(p.size()%2==1) ans+=p[p.size()-1];
    
    for(int i=0; i<m.size()/2; i++){
        ans+=(m[2*i]*m[2*i+1]);
    }
    if(m.size()%2==1) ans+=m[m.size()-1];
    
    cout<<ans;
}