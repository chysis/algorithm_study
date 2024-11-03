#include <iostream>
using namespace std;

pair<int, int> arr[11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        int N;
        cin>>N;
        if(N==-1) break;
        
        for(int i=0; i<N; i++){
            int S, T;
            cin>>S>>T;
            arr[i]={S, T};
        }
        
        int sum=0;
        for(int i=0; i<N; i++){
            if(i==0){
                sum+=arr[i].first*arr[i].second;
            } else{
                sum+=arr[i].first*(arr[i].second-arr[i-1].second);
            }
        }
        
        cout<<sum<<" miles\n";
    }
}