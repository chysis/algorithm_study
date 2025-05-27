#include <bits/stdc++.h>
using namespace std;

int N;
bool visited[33], flag=false;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    if(N==0) return cout<<"NO", 0;
    
    while(N>0){
        for(int i=1; ; i++){
            if(pow(3, i)>N){
                if(visited[i-1]){
                    flag=true;
                    break;
                }
                visited[i-1]=true;
                N-=pow(3, i-1);
                break;
            }
        }
        if(flag) return cout<<"NO", 0;
    }
    cout<<"YES";
}