#include <bits/stdc++.h>
using namespace std;

int T, X, arr[25];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    arr[0]=1, arr[1]=2;
    for(int i=2; i<25; i++) arr[i]=arr[i-1]+arr[i-2];
    
    while(T--){
        cin>>X;
        vector<int> v;
        for(int i=20; i>=0; i--){
            if(arr[i]<=X){
                v.push_back(i);
                X-=arr[i];
            }
        }
        
        for(int i=0; i<v.size(); i++){
            v[i]--;
        }
        
        int temp=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]>=0) temp+=arr[v[i]];
        }
        
        cout<<temp<<"\n";
    }
}