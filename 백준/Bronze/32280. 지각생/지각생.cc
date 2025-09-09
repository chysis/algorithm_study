#include <bits/stdc++.h>
using namespace std;

int N, HH, MM, tt, ll, ans=0;
char c;
string role;
vector<int> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N+1; i++){
        cin>>HH>>c>>MM>>role;
        int t=HH*60+MM;
        if(role=="teacher") tt=t;
        else arr.push_back(t);
    }
    cin>>HH>>c>>MM;
    ll=HH*60+MM;
    
    for(auto a: arr){
        if(ll<=a && tt<=a) ans++;
    }
    cout<<ans;
}