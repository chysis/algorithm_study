#include <iostream>

#define INF 987654321
using namespace std;

int arr[21][21];
int res[21][21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>arr[i][j];
            res[i][j]=arr[i][j];
        }
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(k==i || k==j) continue;
                
                if(arr[i][j]==arr[i][k]+arr[k][j]){
                    res[i][j]=0;
                } else if(arr[i][j]>arr[i][k]+arr[k][j]){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    
    int sum=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            sum+=res[i][j];
        }
    }
    
    cout<<sum/2;
}