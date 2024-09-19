#include <iostream>
#include <algorithm>

#define INF (~0U>>2)
using namespace std;

int N, M, arr1[1000001], arr2[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        cin>>N>>M;
        if(N==0 && M==0) break;
        
        for(int i=0; i<N; i++){
            cin>>arr1[i];
        }
        
        for(int i=0; i<M; i++){
            cin>>arr2[i];
        }
        
        int p1=0, p2=0, ans=0;
        while(p1<N && p2<M){
            if(arr1[p1]==arr2[p2]){
                ans++;
                p1++; p2++;
            } else if(arr1[p1]<arr2[p2]){
                p1++;
            } else{
                p2++;
            }
        }
        
        cout<<ans<<"\n";
    }
}