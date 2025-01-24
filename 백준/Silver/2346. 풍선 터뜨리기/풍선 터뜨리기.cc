#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, arr[1001];
vector<int> ans;
bool popped[1001];

bool isDone(){
    for(int i=1; i<=N; i++){
        if(!popped[i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    int p=1;
    while(true){
        popped[p]=true;
        ans.push_back(p);
        
        if(isDone()) break;

        int num=arr[p];
        
        int cnt=0;
        while(cnt<abs(num)){
            if(num<0){
                p--;
                if(p<1) p=N;
            } else{
                p++;
                if(p>N) p=1;
            }
            
            if(!popped[p]) cnt++;
        }
    }
    
    for(auto a: ans) cout<<a<<" ";
}