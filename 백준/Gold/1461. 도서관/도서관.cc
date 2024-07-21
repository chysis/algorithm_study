#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, M;
deque<int> vPlus, vMinus;

bool comp(int a, int b){
    return abs(a)>abs(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        if(num>0){
            vPlus.push_back(num);
        } else{
            vMinus.push_back(num);
        }
    }
    
    int ans=0;
    sort(vPlus.begin(), vPlus.end(), comp);
    sort(vMinus.begin(), vMinus.end(), comp);
    
    ans-=max(vPlus.front(), -vMinus.front());

    while(!vPlus.empty()){
        ans+=vPlus.front()*2;

        int cnt=0;
        while(!vPlus.empty() && cnt<M){
            vPlus.pop_front();
            cnt++;
        }
    }
    
    while(!vMinus.empty()){
        ans+=abs(vMinus.front())*2;

        int cnt=0;
        while(!vMinus.empty() && cnt<M){
            vMinus.pop_front();
            cnt++;
        }
    }
    
    cout<<ans;
}