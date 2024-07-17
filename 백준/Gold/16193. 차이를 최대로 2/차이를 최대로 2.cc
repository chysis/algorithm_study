#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

long long ans=0;
deque<int> arr;
deque<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());
    
    q.push_back(arr.front());
    arr.pop_front();
    
    for(int i=0; i<N-1; i++){
        int n1=abs(q.front()-arr.front());
        int n2=abs(q.front()-arr.back());
        int n3=abs(q.back()-arr.front());
        int n4=abs(q.back()-arr.back());
        int maxValue=max(max(n1, n2), max(n3, n4));
        
        int target;
        if(maxValue==n1){
            ans+=n1;
            target=arr.front();
            arr.pop_front();
            q.push_front(target);
        } else if(maxValue==n2){
            ans+=n2;
            target=arr.back();
            arr.pop_back();
            q.push_front(target);
        } else if(maxValue==n3){
            ans+=n3;
            target=arr.front();
            arr.pop_front();
            q.push_back(target);
        } else if(maxValue==n4){
            ans+=n4;
            target=arr.back();
            arr.pop_back();
            q.push_back(target);
        }
    }
    
    cout<<ans;
}