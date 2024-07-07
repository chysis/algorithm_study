#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool btn[11];

bool isValid(int N){
    string str=to_string(N);
    for(int j=0; j<str.length(); j++){
        if(!btn[str[j]-'0']) return false;
    }
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<10; i++){
        btn[i]=true;
    }

    int N, M;
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int num;
        cin>>num;
        btn[num]=false;
    }
    
    int ans=abs(N-100);
    
    for(int i=0; i<=1000000; i++){
        if(isValid(i)){
            int ans2=to_string(i).length()+abs(i-N);
            ans=min(ans, ans2);
        }
    }
    
    cout<<ans;
}