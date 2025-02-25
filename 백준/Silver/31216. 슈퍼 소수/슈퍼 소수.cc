#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int T, N, arr[3001];
vector<int> v, sv;
bool chk[333333];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=2; i<=sqrt(333333); i++){
        if(!chk[i]){
            for(int j=i*2; j<=333333; j+=i){
                chk[j]=true;
            }
        }
    }
    
    for(int i=2; i<=333333; i++){
        if(!chk[i]) v.push_back(i);
    }
    
    for(int i=0; i<v.size(); i++){
        if(!chk[i+1]) sv.push_back(v[i]);
    }
    
    cin>>T;
    while(T--){
        cin>>N;
        cout<<sv[N]<<"\n";
    }
}