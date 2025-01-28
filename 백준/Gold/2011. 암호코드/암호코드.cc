#include <iostream>
#include <string>

#define MOD 1000000
using namespace std;

int dp[5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin>>str;
    
    if(str[0]=='0'){
        cout<<0;
        return 0;
    }
    
    dp[0]=1;
    
    if(str.length()>1){
        if(str[1]>='1' && str[1]<='9'){
            if((str[0]-'0')*10+(str[1]-'0')<=26){
                dp[1]=2;
            }else{
                dp[1]=1;
            }
        }else{
            if(str[0]-'0'<3){
                dp[1]=1;
            } else{
                cout<<0;
                return 0;
            }
        }
    }
    
    for(int i=2; i<str.length(); i++){
        if(str[i]>='1' && str[i]<='9'){
            if(str[i-1]>='1' && str[i-1]<='9' && (str[i-1]-'0')*10+(str[i]-'0')<=26){
                dp[i]=(dp[i-1]+dp[i-2])%MOD;
            }else{
                dp[i]=dp[i-1];
            }
        } else{
            if(str[i-1]>='1' && str[i-1]<='9' && (str[i-1]-'0')*10+(str[i]-'0')<=26){
                dp[i]=dp[i-2];
            } else{
                cout<<0;
                return 0;
            }
        }
    }
    
    cout<<dp[str.length()-1];
}