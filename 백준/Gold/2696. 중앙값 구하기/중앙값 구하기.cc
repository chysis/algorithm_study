#include <bits/stdc++.h>
using namespace std;

int T, M, arr[10000];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>M;
        for(int i=1; i<=M; i++){
            cin>>arr[i];
            if(i%2==1){
                sort(arr+1, arr+i+1);
                v.push_back(arr[(i/2)+1]);
            }
        }
        
        cout<<M/2+1;
        for(int i=0; i<v.size(); i++){
            if(i%10==0) cout<<"\n";
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        
        v.clear();
    }
}