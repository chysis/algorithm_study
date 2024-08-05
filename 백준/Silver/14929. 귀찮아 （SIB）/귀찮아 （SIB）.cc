#include <iostream>
#include <algorithm>
using namespace std;

long long ans=0;
int sum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        if(i==0) sum[i]=num;
        else sum[i]=sum[i-1]+num;
    }
    
    for(int i=N-1; i>0; i--){
        ans+=sum[i-1]*(sum[i]-sum[i-1]);
    }
    
    cout<<ans;
}