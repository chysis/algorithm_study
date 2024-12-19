#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
char map[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, N;
    cin>>T;
    while(T--){
        int ans=0;
        cin>>N;
        for(int i=0; i<N; i++){
            char c;
            cin>>c;
            arr[i]=c-'0';
        }
        
        for(int i=0; i<N; i++){
            cin>>map[i];
        }
        
        // 이미 있는 지뢰 확인
        for(int i=0; i<N; i++){
            if(map[i]=='*'){
                if(i==0) arr[i]--, arr[i+1]--;
                else if(i==N-1) arr[i-1]--, arr[i]--;
                else arr[i-1]--, arr[i]--, arr[i+1]--;
                ans++;
            }
        }
        
        for(int i=0; i<N; i++){
            if(i==0 && arr[i]>0 && arr[i+1]>0){
                arr[i]--;
                arr[i+1]--;
                ans++;
            } else if(i==N-1 && arr[i-1]>0 && arr[i]>0){
                arr[i-1]--;
                arr[i]--;
                ans++;
            } else if(arr[i-1]>0 && arr[i]>0 && arr[i+1]>0){
                arr[i-1]--;
                arr[i]--;
                arr[i+1]--;
                ans++;
            }
        }
        
        cout<<ans<<"\n";
        
        
    }
}