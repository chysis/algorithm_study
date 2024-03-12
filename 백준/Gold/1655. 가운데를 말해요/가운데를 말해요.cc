#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int, vector<int>, less<int>> max_pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        if(i==0) max_pq.push(num);
        else if(i==1){
            if(num>max_pq.top()){
                min_pq.push(num);
            }
            else{
                min_pq.push(max_pq.top());
                max_pq.pop();
                max_pq.push(num);
            }
        }
        else{
            if(min_pq.size()==max_pq.size()){
                if(num>min_pq.top()){
                    max_pq.push(min_pq.top());
                    min_pq.pop();
                    min_pq.push(num);
                }
                else max_pq.push(num);
            }
            else{
                if(num<max_pq.top()){
                    min_pq.push(max_pq.top());
                    max_pq.pop();
                    max_pq.push(num);
                }
                else min_pq.push(num);
            }
        }
        cout<<max_pq.top()<<"\n";
    }
}