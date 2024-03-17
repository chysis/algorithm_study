#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        int num;
        cin>>num;
        if((i%2==0 && num%2==1) || (i%2==1 && num%2==0)){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}