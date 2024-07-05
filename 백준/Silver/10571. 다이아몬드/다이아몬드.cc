#include <iostream>

#define pdd pair<double, double>
using namespace std;

pdd arr[201];
int dp[201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        for(int i=0; i<N; i++){
            double w, c;
            cin>>w>>c;
            arr[i]={w, c};
        }
        
        for(int i=0; i<N; i++){
            dp[i]=1;
        }
        
        for(int i=1; i<N; i++){
            for(int j=0; j<i; j++){
                if(arr[j].first<arr[i].first && arr[j].second>arr[i].second){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }
        
        int ans=-1;
        for(int i=0; i<N; i++){
            ans=max(ans, dp[i]);
        }
        
        cout<<ans<<"\n";
    }
}