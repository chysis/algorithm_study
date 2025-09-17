#include <bits/stdc++.h>
using namespace std;

int N, M;
long long ans=1;
vector<int> v;
bool used[11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N-1; i++) v.push_back(M-1-i);
    for(int i=0; i<N-1; i++){
        for(int j=0; j<v.size(); j++){
            if(!used[i]){
                if(v[j]%(N-1-i)==0){
                    used[i]=true;
                    v[j]/=(N-1-i);
                    break;
                }
            }
        }
    }
    for(int i=0; i<N-1; i++) ans*=v[i];
    for(int i=0; i<N-1; i++){
        if(!used[i]) ans/=(N-1-i);
    }
    cout<<ans;
}