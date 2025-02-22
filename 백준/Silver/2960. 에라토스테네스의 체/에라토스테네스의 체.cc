#include <iostream>
using namespace std;

int N, K, cnt=0;
bool board[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=2; i<=N; i++){
        if(!board[i]){
            for(int j=i; j<=N; j+=i){
                if(!board[j]){
                    board[j]=true;
                    cnt++;
                    
                    if(cnt==K){
                        cout<<j;
                        return 0;
                    }
                }
            }
        }
    }
}