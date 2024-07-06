#include <iostream>
#include <algorithm>

#define INF 1000000001
#define ll long long
#define MAX 100001
using namespace std;

ll arr[MAX];
ll mintree[MAX*4];
ll maxtree[MAX*4];

ll initMin(int node, int start, int end){
    if(start==end){
        return mintree[node]=arr[start];
    }
    
    int mid=(start+end)/2;
    
    return mintree[node]=min(initMin(node*2, start, mid), initMin(node*2+1, mid+1, end));
}

ll initMax(int node, int start, int end){
    if(start==end){
        return maxtree[node]=arr[start];
    }
    
    int mid=(start+end)/2;
    
    return maxtree[node]=max(initMax(node*2, start, mid), initMax(node*2+1, mid+1, end));
}

ll minValue(int node, int start, int end, int left, int right){
    if(left>end || right<start) return INF;
    if(left<=start && end<=right) return mintree[node];
    
    int mid=(start+end)/2;
    return min(minValue(node*2, start, mid, left, right), minValue(node*2+1, mid+1, end, left, right));
}

ll maxValue(int node, int start, int end, int left, int right){
    if(left>end || right<start) return -INF;
    if(left<=start && end<=right) return maxtree[node];
    
    int mid=(start+end)/2;
    return max(maxValue(node*2, start, mid, left, right), maxValue(node*2+1, mid+1, end, left, right));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    initMin(1, 1, N);
    initMax(1, 1, N);
    
    for(int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        cout<<minValue(1, 1, N, a, b)<<" "<<maxValue(1, 1, N, a, b)<<"\n";
    }
}