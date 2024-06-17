#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF (~0U>>2)
#define DIV 1000000007
#define ll long long
#define vll vector<long long>
using namespace std;

ll init(vll& arr, vll& tree, int node, int start, int end){
    if(start==end){
        return tree[node]=arr[start];
    }
    
    int mid=(start+end)/2;
    return tree[node]=(init(arr, tree, node*2, start, mid)*init(arr, tree, node*2+1, mid+1, end))%DIV;
}

ll solve(vll& tree, int node, int left, int right, int start, int end){
    if(left>end || right<start) return 1;
    if(left<=start && end<=right) return tree[node];
    
    int mid=(start+end)/2;
    return (solve(tree, node*2, left, right, start, mid) * solve(tree, node*2+1, left, right, mid+1, end)) % DIV;
}

ll update(vll& tree, int node, int start, int end, int index, ll prevValue, ll newValue){
    if(index<start || index>end) return tree[node];
    if(start==end) return tree[node]=newValue;
    
    if(start!=end){
        int mid=(start+end)/2;
        return tree[node]=(update(tree, node*2, start, mid, index, prevValue, newValue)*
        update(tree, node*2+1, mid+1, end, index, prevValue, newValue))%DIV;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K;
    cin>>N>>M>>K;
    
    int h=(int)ceil(log2(N));
    int treeSize=(1<<(h+1));
    
    vll arr(N+1);
    vll tree(treeSize+1);
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    init(arr, tree, 1, 1, N);
    
    for(int i=0; i<M+K; i++){
        int A, B, C;
        cin>>A;
        if(A==1){
            cin>>B>>C;
            ll prev=arr[B];
            arr[B]=C;
            update(tree, 1, 1, N, B, prev, C);
        } else if(A==2){
            cin>>B>>C;
            cout<<solve(tree, 1, B, C, 1, N)<<"\n";
        }
    }
}