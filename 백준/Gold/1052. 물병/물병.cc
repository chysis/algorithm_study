#include <iostream>
#include <cmath>
using namespace std;

int N, K, expo[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    
    if(N<=K){
        cout<<0;
        return 0;
    }
    
    expo[0]=N;
    
    for(int i=0; i<24; i++){
        if(expo[i]>=2){
            expo[i+1]+=(expo[i]/2);
            expo[i]%=2;
        }
    }
    
    int temp=0;
    for(int i=0; i<24; i++){
        temp+=expo[i];
    }
    
    if(temp<=K){
        cout<<0;
        return 0;
    }
    
    int target=0, cnt=0;
    for(int i=24; i>=0; i--){
        if(expo[i]==1){
            cnt++;
            if(K==cnt){
                bool flag=false;
                for(int j=i-1; j>=0; j--){
                    if(expo[j]==1){
                        flag=true;
                        break;
                    }
                }
                
                if(!flag){
                    cout<<0;
                    return 0;
                } else{
                    target=i+1;
                    break;
                }
            }
        }
    }
    
    int targetNum=pow(2, target);
    for(int i=target-1; i>=0; i--){
        if(expo[i]==1){
            targetNum-=pow(2, i);
        }
    }
    
    cout<<targetNum;
}