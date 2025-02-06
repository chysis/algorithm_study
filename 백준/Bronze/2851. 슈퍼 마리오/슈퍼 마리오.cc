#include <iostream>
#include <cmath>
using namespace std;

int sum[11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=1; i<=10; i++){
        int num;
        cin>>num;
        sum[i]=sum[i-1]+num;
    }
    
    bool flag=false;
    for(int i=1; i<=10; i++){
        if(sum[i]>=100){
            flag=true;
            cout<<(abs(100-sum[i])<=abs(100-sum[i-1]) ? sum[i] : sum[i-1]);
            break;
        }
    }
    
    if(!flag){
        cout<<sum[10];
    }
}