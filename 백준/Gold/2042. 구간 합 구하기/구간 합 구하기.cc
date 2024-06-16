#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define vll vector<long long>
using namespace std;

ll init(vll& arr, vll& tree, int node, int start, int end){
    if(start==end){
        return tree[node] = arr[start];
    }
    
    int mid=(start+end)/2;
    return tree[node] = init(arr, tree, node*2, start, mid) + init(arr, tree, node*2+1, mid+1, end);
}

ll sum(vll& tree, int node, int start, int end, int left, int right){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    
    int mid=(start+end)/2;
    return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}

void update(vll& tree, int node, int start, int end, int index, ll diff){
    if(index<start || index>end) return;
    tree[node] += diff;
    
    if(start!=end){
        int mid=(start+end)/2;
        update(tree, node*2, start, mid, index, diff);
        update(tree, node*2+1, mid+1, end, index, diff);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K;
    cin>>N>>M>>K;
    
    int h = (int)ceil(log2(N));
    int treeSize = (1<<(h+1));
    
    vll arr(N+1);
    vll tree(treeSize+1);
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    init(arr, tree, 1, 1, N);
    
    for(int i=0; i<M+K; i++){
        int A, B;
        ll C;
        cin>>A;
        if(A==1){
            cin>>B>>C;
            ll diff=C-arr[B];
            arr[B]=C;
            update(tree, 1, 1, N, B, diff);
        } else if(A==2){
            cin>>B>>C;
            cout<<sum(tree, 1, 1, N, B, C)<<"\n";
        }
    }
}