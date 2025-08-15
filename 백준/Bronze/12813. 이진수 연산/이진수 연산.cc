#include <bits/stdc++.h>
using namespace std;

string A, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>A>>B;
    for(int i=0; i<A.length(); i++){
        if(A[i]=='1' && B[i]=='1') cout<<1;
        else cout<<0;
    }
    cout<<"\n";
    for(int i=0; i<A.length(); i++){
        if(A[i]=='0' && B[i]=='0') cout<<0;
        else cout<<1;
    }
    cout<<"\n";
    for(int i=0; i<A.length(); i++){
        if(A[i]!=B[i]) cout<<1;
        else cout<<0;
    }
    cout<<"\n";
    for(int i=0; i<A.length(); i++){
        if(A[i]=='1') cout<<0;
        else cout<<1;
    }
    cout<<"\n";
    for(int i=0; i<B.length(); i++){
        if(B[i]=='1') cout<<0;
        else cout<<1;
    }
}