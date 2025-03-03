#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A, B, M, num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>A>>B>>M;
    
    ll res=0;
    for(int i=0; i<M; i++){
        cin>>num;
        res+=(num*pow(A, M-i-1));
    }
    
    vector<int> v;
    while(res>0){
        v.push_back(res%B);
        res/=B;
    }
    
    reverse(v.begin(), v.end());
    for(auto a: v) cout<<a<<" ";
}