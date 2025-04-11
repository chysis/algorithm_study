#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[11][11], narr[11][22], target[11][22];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<2*M; j++){
            cin>>target[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            narr[i][2*j]=arr[i][j];
            narr[i][2*j+1]=arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<2*M; j++){
            if(narr[i][j]!=target[i][j]){
                cout<<"Not Eyfa";
                return 0;
            }
        }
    }
    
    cout<<"Eyfa";
}