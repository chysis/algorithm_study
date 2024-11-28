#include <iostream>
#include <string>
using namespace std;

int num[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin>>str;
    
    int sum=0;
    for(int i=0; i<str.length(); i++){
        num[str[i]-'0']++;
        sum+=str[i]-'0';
    }
    
    if(num[0]==0 || sum%3!=0){
        cout<<-1;
        return 0;
    }
    
    for(int i=9; i>=0; i--){
        for(int j=0; j<num[i]; j++){
            cout<<i;
        }
    }
}