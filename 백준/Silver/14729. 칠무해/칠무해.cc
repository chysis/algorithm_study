#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue<double, vector<double>, greater<double>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        double d;
        cin>>d;
        pq.push(d);
    }
    
    cout<<fixed;
    cout.precision(3);
    
    for(int i=0; i<7; i++){
        cout<<pq.top()<<"\n";
        pq.pop();
    }
}