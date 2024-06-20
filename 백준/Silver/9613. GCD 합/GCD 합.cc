#include <iostream>
using namespace std;

int arr[101];

int gcd(int a, int b){
    return (a%b==0) ? b : gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }
        
        long long sum=0;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                sum+=gcd(arr[i], arr[j]);
            }
        }
        
        cout<<sum<<"\n";
    }
}