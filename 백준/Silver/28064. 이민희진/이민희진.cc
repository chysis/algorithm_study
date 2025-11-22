#include <bits/stdc++.h>
using namespace std;

int N, ans=0;
string arr[101];

bool solve(string A, string B){
    int maxLen=min(A.length(), B.length());
    for(int i=1; i<=maxLen; i++){
        if(A.substr(A.length()-i, i)==B.substr(0, i) ||
        B.substr(B.length()-i, i)==A.substr(0, i)) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(solve(arr[i], arr[j])) ans++;
        }
    }
    cout<<ans;
}