#include <bits/stdc++.h>
using namespace std;

int N, A, B;
pair<int, int> arr[50001];

int solve(int cur, int A, int B){
    int k=cur/(A+B);
    if(cur>=k*(A+B)+B && cur<(k+1)*(A+B)) return -1;
    else return k*(A+B)+B-cur;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A>>B;
        arr[i]={A, B};
    }
    
    int cnt=0;
    for(int i=0; i<N; i++){
        int temp=solve(cnt, arr[i].first, arr[i].second);
        if(temp!=-1) cnt+=temp;
        cnt++;
    }
    
    cout<<cnt;
}