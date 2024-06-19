#include <iostream>
#include <algorithm>
using namespace std;

int weight[5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, C;
    cin>>N>>C;
    
    for(int i=0; i<N; i++){
        cin>>weight[i];
        if(weight[i]==C){
            cout<<1;
            return 0;
        }
    }
    
    sort(weight, weight+N);
    
    int s=0, e=N-1;
    while(s<e){
        int sum=weight[s]+weight[e];
        if(sum==C){
            cout<<1;
            return 0;
        } else if(sum<C){
            s++;
        } else {
            e--;
        }
    }
    
    for(int i=0; i<N-2; i++){
        int target=C-weight[i];
        
        int s=i+1, e=N-1;
        while(s<e){
            int sum=weight[s]+weight[e];
            if(sum==target){
                cout<<1;
                return 0;
            } else if(sum<target){
                s++;
            } else{
                e--;
            }
        }
    }
    
    cout<<0;
}