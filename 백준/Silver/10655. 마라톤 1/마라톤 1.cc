#include <iostream>
#include <cmath>

#define INF 987654321
using namespace std;

pair<int, int> arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        arr[i]={x, y};
    }
    
    int sum=0;
    for(int i=0; i<N-1; i++){
        sum+=(abs(arr[i].first-arr[i+1].first)+abs(arr[i].second-arr[i+1].second));
    }
    
    int ans=INF;
    for(int i=1; i<N-1; i++){
        int temp=sum;
        temp-=(abs(arr[i-1].first-arr[i].first)+abs(arr[i-1].second-arr[i].second));
        temp-=(abs(arr[i].first-arr[i+1].first)+abs(arr[i].second-arr[i+1].second));
        temp+=(abs(arr[i-1].first-arr[i+1].first)+abs(arr[i-1].second-arr[i+1].second));
        ans=min(ans, temp);
    }
    
    cout<<ans;
}