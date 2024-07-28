#include <iostream>
#include <algorithm>

#define INF 3000000001
#define ll long long
using namespace std;

int arr[5001];
ll diff=INF;
int ans[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N);
    
    bool isDone=false;
    for(int i=0; i<N-2; i++){
        ll target=-arr[i];
        
        int s=i+1, e=N-1;
        ll sum;
        while(s<e){
            sum=arr[s]+arr[e];
            if(abs(target-sum)<diff){
                diff=abs(target-sum);
                ans[0]=arr[i];
                ans[1]=arr[s];
                ans[2]=arr[e];
            }
            
            if(sum>target) e--;
            else if(sum<target) s++;
            else {
                isDone=true;
                break;
            }
        }
        
        if(isDone) break;
    }
    
    sort(ans, ans+3);
    for(int i=0; i<3; i++){
        cout<<ans[i]<<" ";
    }
}