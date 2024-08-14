#include <iostream>
using namespace std;

int cnt=0;
int arr[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, N;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }
        
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    cnt++;
                }
            }
        }
        
        cout<<cnt<<"\n";
        cnt=0;
    }
}