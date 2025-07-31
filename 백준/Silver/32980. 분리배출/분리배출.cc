#include <bits/stdc++.h>
using namespace std;

int N, P, C, V, S, G, F, O;
string arr[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    cin>>P>>C>>V>>S>>G>>F>>O;
    
    long long ans=0;
    for(int i=0; i<N; i++){
        int p=0, c=0, v=0, s=0, g=0, f=0, o=0;
        for(int j=0; j<arr[i].length(); j++){
            if(arr[i][j]=='P') p++;
            else if(arr[i][j]=='C') c++;
            else if(arr[i][j]=='V') v++;
            else if(arr[i][j]=='S') s++;
            else if(arr[i][j]=='G') g++;
            else if(arr[i][j]=='F') f++;
            else if(arr[i][j]=='O') o++;
        }
        
        int cnt=0;
        if(p>0) cnt++;
        if(c>0) cnt++;
        if(v>0) cnt++;
        if(s>0) cnt++;
        if(g>0) cnt++;
        if(f>0) cnt++;
        if(o>0) cnt++;
        
        if(cnt>1) ans+=arr[i].length()*O;
        else{
            if(p>0) ans+=arr[i].length()*min(O, P);
            else if(c>0) ans+=arr[i].length()*min(O, C);
            else if(v>0) ans+=arr[i].length()*min(O, V);
            else if(s>0) ans+=arr[i].length()*min(O, S);
            else if(g>0) ans+=arr[i].length()*min(O, G);
            else if(f>0) ans+=arr[i].length()*min(O, F);
            else if(o>0) ans+=arr[i].length()*O;
        }
    }
    cout<<ans;
}