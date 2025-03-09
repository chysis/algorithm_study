#include <bits/stdc++.h>
using namespace std;

int N, num;
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    while(true){
        cin>>num;
        if(num==-1) break;
        
        if(num==0) q.pop();
        else{
            if(q.size()==N) continue;
            else q.push(num);
        }
    }
    
    if(q.empty()) cout<<"empty";
    else{
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
    }
}