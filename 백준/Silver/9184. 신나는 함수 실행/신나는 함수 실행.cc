#include <iostream>
using namespace std;

int dp[55][55][55];

int solve(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0) return 1;
    int& ret=dp[a][b][c];
    if(ret!=-1) return ret;
    
    if(a>20 || b>20 || c>20) return ret=solve(20, 20, 20);
    if(a<b && b<c) return ret=solve(a, b, c-1)+solve(a, b-1, c-1)-solve(a, b-1, c);
    ret=solve(a-1, b, c)+solve(a-1, b-1, c)+solve(a-1, b, c-1)-solve(a-1, b-1, c-1);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<55; i++){
        for(int j=0; j<55; j++){
            for(int k=0; k<55; k++){
                dp[i][j][k]=-1;
            }
        }
    }
    
    while(true){
        int A, B, C;
        cin>>A>>B>>C;
        if(A==-1 && B==-1 && C==-1) break;
        
        cout<<"w("<<A<<", "<<B<<", "<<C<<") = "<<solve(A, B, C)<<"\n";
    }
}