#include <bits/stdc++.h>
using namespace std;

int T, R, C;
char arr[401][401];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>R>>C;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin>>arr[i][j];
            }
        }
        
        int cnt=0;
        for(int i=0; i<R; i++){
            for(int j=0; j<C-2; j++){
                if(arr[i][j]=='>' && arr[i][j+1]=='o' && arr[i][j+2]=='<'){
                    cnt++;
                }
            }
        }
        
        for(int i=0; i<C; i++){
            for(int j=0; j<R-2; j++){
                if(arr[j][i]=='v' && arr[j+1][i]=='o' && arr[j+2][i]=='^'){
                    cnt++;
                }
            }
        }
        
        cout<<cnt<<"\n";
    }
}