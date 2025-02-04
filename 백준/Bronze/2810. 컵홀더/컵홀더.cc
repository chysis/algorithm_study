#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, Lcnt=0;
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>str;
    
    int ans=1;
    for(int i=0; i<N; i++){
        if(str[i]=='L'){
            if(Lcnt==0){
                Lcnt++;
            } else if(Lcnt==1){
                ans++;
                Lcnt--;
            }
            continue;
        }
        ans++;
    }
    
    cout<<min(ans, N);
}