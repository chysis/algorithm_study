#include <iostream>
#include <algorithm>

#define INF (~0U>>2)
using namespace std;

int arr[601];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N);
    
    int s1, e1, s2, e2, ans=INF;
    bool flag=false;
    
    for(int i=0; i<N-3; i++){
        for(int j=i+3; j<N; j++){
            s1=i, e1=j, s2=i+1, e2=j-1;
            int sum1=arr[s1]+arr[e1], temp=INF;
            
            while(s2<e2){
                int diff=sum1-(arr[s2]+arr[e2]);
                if(abs(diff)<abs(temp)){
                    temp=diff;
                }
                
                if(diff<0) e2--;
                else if(diff>0) s2++;
                else{
                    ans=0;
                    flag=true;
                    break;
                }
            }
            
            if(flag) break;

            if(abs(temp)<abs(ans)) ans=temp;
        }
    }
    
    cout<<abs(ans);
}