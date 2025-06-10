#include <bits/stdc++.h>
using namespace std;

int N, arr[51][51], ans=0;
bool tf[51][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c; cin>>c;
            if(c=='N') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]){
                tf[i][j]=true;
                for(int k=0; k<N; k++){
                    if(k==i) continue;
                    if(arr[j][k]) tf[i][k]=true;
                }
            }
        }
    }
    
    for(int i=0; i<N; i++){
        int temp=0;
        for(int j=0; j<N; j++){
            if(tf[i][j]) temp++;
        }
        ans=max(ans, temp);
    }
    cout<<ans;
}