#include <iostream>
using namespace std;

int sum[200002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    sum[0]=0;
    sum[1]=1;
    for(int i=2; i<=N+1; i++){
        int opt;
        cin>>opt;
        if(opt==1){
            int x, y;
            cin>>x>>y;
            if(sum[y]-sum[x-1]==y-x+1) {
                cout<<"Yes\n";
                sum[i]=sum[i-1]+1;
            }
            else {
                cout<<"No\n";
                sum[i]=sum[i-1];
            }
        } else{
            int x, y;
            cin>>x>>y;
            if(sum[y]-sum[x-1]==0) {
                cout<<"Yes\n";
                sum[i]=sum[i-1]+1;
            }
            else {
                cout<<"No\n";
                sum[i]=sum[i-1];
            }
        }
    }
}