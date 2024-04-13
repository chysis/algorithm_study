#include <iostream>
#include <algorithm>

#define pii pair<int, int>
using namespace std;

pii arr[101];
int dp[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int A, B;
        cin>>A>>B;
        arr[i]={A, B};
    }
    
    sort(arr, arr+N);
    
    for(int i=0; i<N; i++){
        dp[i]=1;
        for(int j=0; j<i; j++){
            if(arr[j].second<arr[i].second){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
    }
    
    int maxVal=-1;
    for(int i=0; i<N; i++){
        maxVal=max(maxVal, dp[i]);
    }
    
    cout<<N-maxVal;
}