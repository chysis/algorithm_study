#include <iostream>
#include <string>
#include <cmath>
using namespace std;

char arr[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        int leng=sqrt(str.length());
        
        for(int i=0; i<str.length(); i++){
            arr[i/leng][i%leng]=str[i];
        }
        
        for(int i=leng-1; i>=0; i--){
            for(int j=0; j<leng; j++){
                cout<<arr[j][i];
            }
        }
        cout<<"\n";
    }
}