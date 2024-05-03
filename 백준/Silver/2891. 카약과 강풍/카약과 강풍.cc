#include <iostream>
using namespace std;

bool broke[11];
bool oneMore[11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, S, R;
    cin>>N>>S>>R;
    for(int i=0; i<S; i++){
        int num;
        cin>>num;
        broke[num]=true;
    }
    
    int ans=S;
    for(int i=0; i<R; i++){
        int num;
        cin>>num;
        oneMore[num]=true;
    }
    
    for(int i=N; i>=1; i--){
        if(oneMore[i]){
            if(broke[i]){
                ans--;
                broke[i]=false;
                continue;
            }
            
            if(broke[i+1]){
                ans--;
                broke[i+1]=false;
                continue;
            }
            
            if(broke[i-1] && !oneMore[i-1]){
                ans--;
                broke[i-1]=false;
                continue;
            }
        }
    }
    
    cout<<ans;
}