#include <bits/stdc++.h>
using namespace std;

int M, N, K, A, B, C, D;
char arr[1002][1002];
tuple<int, int, int> sum[1002][1002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>M>>N>>K;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            sum[i][j]={get<0>(sum[i-1][j])+get<0>(sum[i][j-1])-get<0>(sum[i-1][j-1])+(arr[i][j]=='J' ? 1 : 0),
                get<1>(sum[i-1][j])+get<1>(sum[i][j-1])-get<1>(sum[i-1][j-1])+(arr[i][j]=='O' ? 1 : 0),
                get<2>(sum[i-1][j])+get<2>(sum[i][j-1])-get<2>(sum[i-1][j-1])+(arr[i][j]=='I' ? 1 : 0)
            };
        }
    }
    
    for(int i=0; i<K; i++){
        cin>>A>>B>>C>>D;
        cout<<(get<0>(sum[C][D])-get<0>(sum[A-1][D])-get<0>(sum[C][B-1])+get<0>(sum[A-1][B-1]))<<" "
            <<(get<1>(sum[C][D])-get<1>(sum[A-1][D])-get<1>(sum[C][B-1])+get<1>(sum[A-1][B-1]))<<" "
            <<(get<2>(sum[C][D])-get<2>(sum[A-1][D])-get<2>(sum[C][B-1])+get<2>(sum[A-1][B-1]))<<"\n";
    }
}