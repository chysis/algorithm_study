#include <bits/stdc++.h>
using namespace std;

int N, H, M, arr[200001];
char c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>H>>c>>M;
        arr[i]=H*60+M;
    }
    
    sort(arr, arr+N);
    
    int s=0, ans=0, temp=0;
    for(int i=0; i<N; i++){
        if(i==0){
            ans++;
            s=arr[i];
            temp++;
        }else{
            if(temp==3){
                ans++;
                s=arr[i];
                temp=1;
            }else{
                if(arr[i]-s>20){
                    ans++;
                    s=arr[i];
                    temp=1;
                }else{
                    temp++;
                }
            }
        }
    }
    
    cout<<ans;
}