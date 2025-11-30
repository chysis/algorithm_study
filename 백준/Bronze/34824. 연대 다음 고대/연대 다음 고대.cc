#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, flag=0;
    string S;
    cin>>N;
    while(N--){
        cin>>S;
        if(S=="yonsei"){
            if(flag==0) flag=1;
        }
        else if(S=="korea"){
            if(flag==0) flag=2;
        }
    }
    
    if(flag==1) cout<<"Yonsei Won!";
    else cout<<"Yonsei Lost...";
}