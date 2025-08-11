#include <bits/stdc++.h>
using namespace std;

string A, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>A>>B;
    if(A.length()==B.length()){
        int cnt=0;
        for(int i=0; i<A.length(); i++){
            if(A[i]!=B[i]) cnt++;
        }
        cout<<cnt;
        return 0;
    }
    
    int ans=99;
    // i: size of string, j: start index
    for(int i=0; i<B.length()-A.length()+1; i++){
        int temp=0;
        for(int j=0; j<A.length(); j++){
            if(A[j]!=B[i+j]) temp++;
        }
        ans=min(ans, temp);
    }
    cout<<ans;
}