#include <iostream>
#include <stack>
using namespace std;

int arr[1001];
stack<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    int now=1, idx=1;
    while(true){
        if(now>N || idx>N) break;
        
        if(arr[idx]==now){
            idx++;
            now++;
        } else{
            if(!s.empty() && s.top()==now){
                now++;
                s.pop();
            } else{
                s.push(arr[idx]);
                idx++;
            }
        }
    }
    
    while(!s.empty() && s.top()==now){
        s.pop();
        now++;
    }
    
    if(now==N+1) cout<<"Nice";
    else cout<<"Sad";
}