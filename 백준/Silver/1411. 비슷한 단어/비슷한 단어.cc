#include <bits/stdc++.h>
using namespace std;

int N, arr[101][51];
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>S;
        
        int temp[27];
        fill(temp, temp+26, -1);
        int ord=1;
        for(int j=0; j<S.length(); j++){
            if(temp[S[j]-'a']==-1) temp[S[j]-'a']=ord++;
            arr[i][j]=temp[S[j]-'a'];
        }
    }
    
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            bool flag=true;
            for(int k=0; k<S.length(); k++){
                if(arr[i][k]!=arr[j][k]){
                    flag=false;
                    break;
                }
            }
            
            if(flag) ans++;
        }
    }
    
    cout<<ans;
}