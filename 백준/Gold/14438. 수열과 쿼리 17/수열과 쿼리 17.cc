#include <iostream>
#include <algorithm>

#define ll long long
#define MAX 100001
#define INF (~0U<<2)
using namespace std;

ll arr[MAX];
ll tree[4*MAX];

ll init(int node, int start, int end){
    if(start==end){
        return tree[node]=arr[start];
    }
    
    int mid=(start+end)/2;
    return tree[node]=min(init(node*2, start, mid), init(node*2+1, mid+1, end));
}

ll solve(int node, int start, int end, int left, int right){
    if(left>end || right<start) return INF;
    if(left<=start && end<=right) return tree[node];
    
    int mid=(start+end)/2;
    return min(solve(node*2, start, mid, left, right), solve(node*2+1, mid+1, end, left, right));
}

ll update(int node, int start, int end, int index, ll newValue){
    if(index<start || index>end) return tree[node];
    if(start==end) return tree[node]=newValue;
    
    if(start!=end){
        int mid=(start+end)/2;
        return tree[node]=min(update(node*2, start, mid, index, newValue),
        update(node*2+1, mid+1, end, index, newValue));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    init(1, 1, N);
    
    cin>>M;
    for(int i=0; i<M; i++){
        int A, B, C;
        cin>>A;
        
        if(A==1){
            cin>>B>>C;
            update(1, 1, N, B, C);
        } else if(A==2){
            cin>>B>>C;
            cout<<solve(1, 1, N, B, C)<<"\n";
        }
    }
}