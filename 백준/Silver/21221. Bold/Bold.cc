#include <iostream>
using namespace std;

char arr[101][101], ans[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            ans[i][j]=arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]=='#'){
                ans[i][j]='#';
                ans[i+1][j]='#';
                ans[i][j+1]='#';
                ans[i+1][j+1]='#';
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
}