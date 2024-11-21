#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int A;
        cin>>A;
        if(A==0){
            if(pq.empty()){
                cout<<-1<<"\n";
            } else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
            
            continue;
        }
        
        for(int j=0; j<A; j++){
            int num;
            cin>>num;
            pq.push(num);
        }
    }
}