#include <iostream>
using namespace std;

int G, P, g[100001], dock[100001];
bool used[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>G>>P;
    for(int i=1; i<=P; i++){
        cin>>g[i];
    }

    for(int i=1; i<=P; i++){
        bool flag=false;
        int start=(dock[g[i]]==0 ? g[i] : dock[g[i]]-1);
        
        for(int j=start; j>=1; j--){
            if(!used[j]){
                used[j]=true;
                dock[g[i]]=j;
                flag=true;
                break;
            }
        }
        
        if(!flag){
            cout<<i-1;
            return 0;
        }
    }
    
    cout<<P;
}