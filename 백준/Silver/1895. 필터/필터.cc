#include <bits/stdc++.h>
using namespace std;

int R, C, T, arr[41][41], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>arr[i][j];
        }
    }
    cin>>T;
    
    for(int i=1; i<R-1; i++){
        for(int j=1; j<C-1; j++){
            vector<int> v;
            for(int x=i-1; x<=i+1; x++){
                for(int y=j-1; y<=j+1; y++){
                    v.push_back(arr[x][y]);
                }
            }
            sort(v.begin(), v.end());
            if(v[4]>=T) ans++;
        }
    }
    cout<<ans;
}