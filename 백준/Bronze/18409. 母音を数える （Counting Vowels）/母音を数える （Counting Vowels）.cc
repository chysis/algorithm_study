#include <iostream>
using namespace std;

int main()
{
    int N, cnt=0;
    cin>>N;
    for(int i=0; i<N; i++){
        char c;
        cin>>c;
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') cnt++;
    }
    
    cout<<cnt;
}