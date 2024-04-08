#include <iostream>
using namespace std;

int arr[1001];
int friends[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<M; i++){
        cin>>friends[i];
    }
    
    int ans=0;
    for(int i=0; i<M; i++){
        bool flag=false;
        for(int j=0; j<M; j++){
            if(arr[j]==friends[i]){
                flag=true;
                break;
            }
        }
        if(!flag) ans++;
    }
    cout<<ans;
}