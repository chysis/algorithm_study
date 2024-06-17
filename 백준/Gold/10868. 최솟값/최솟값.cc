#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF (~0U>>2)
#define ll long long
#define vll vector<long long>
using namespace std;

ll init(vll& arr, vll& tree, int node, int start, int end){
    if(start==end){
        return tree[node]=arr[start];
    }
    
    int mid=(start+end)/2;
    return tree[node]=min(init(arr, tree, node*2, start, mid), init(arr, tree, node*2+1, mid+1, end));
}

ll solve(vll& tree, int node, int left, int right, int start, int end){
    if(left>end || right<start) return INF;
    if(left<=start && end<=right) return tree[node];
    
    int mid=(start+end)/2;
    return min(solve(tree, node*2, left, right, start, mid), solve(tree, node*2+1, left, right, mid+1, end));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    int N, M;
    cin>>N>>M;
    
    int h=(int)ceil(log2(N));
    int treeSize=(1<<(h+1));
    
    vll arr(N+1);
    vll tree(treeSize+1);
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    init(arr, tree, 1, 1, N);
    
    for(int i=0; i<M; i++){
        int A, B;
        cin>>A>>B;
        cout<<solve(tree, 1, A, B, 1, N)<<"\n";
    }
}