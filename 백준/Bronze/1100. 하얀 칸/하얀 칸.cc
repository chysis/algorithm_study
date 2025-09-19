#include <bits/stdc++.h>
using namespace std;

int ans=0;
char arr[9][9];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>arr[i][j];
            if((i+j)%2==0 && arr[i][j]=='F') ans++;
        }
    }
    cout<<ans;
}