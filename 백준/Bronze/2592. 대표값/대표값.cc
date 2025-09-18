#include <bits/stdc++.h>
using namespace std;

int arr[11], cnt[101], sum=0, maxVal=-1, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<10; i++){
        cin>>arr[i];
        sum+=arr[i];
        cnt[arr[i]/10]++;
    }
    for(int i=1; i<=100; i++){
        if(maxVal<cnt[i]){
            maxVal=cnt[i];
            ans=i;
        }
    }
    cout<<sum/10<<"\n"<<ans*10;
}